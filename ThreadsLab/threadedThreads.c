#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

int arraySize(FILE *file);
void *dotProduct(void *arg);

typedef struct Struct
{
	int *firstArray;
	int *seconArray;
	int start;
	int numComputation;
	int dotProduct;
} Struct;

int main(int argc, char *argv[])
{
	if (argc != 4) {
		printf("Numero incorrecto de argumentos\n");
		printf("Formato permitido: ./secuentialThreads <file1> <file2> <numeroDeHilos>\n");
		exit(EXIT_FAILURE);
	}	
	int arg = atoi(argv[3]);
	if (arg != 2 && arg != 4 && arg != 8 && arg != 16)
	{
		printf("Numero incorrecto de argumentos\n");
		printf("Formato permitido: ./secuentialThreads <file1> <file2> <numeroDeHilos>\n");
		exit(EXIT_FAILURE);
	}
	FILE *fileOne = fopen(argv[1], "r"), *fileTwo = fopen(argv[2], "r");
	if (fileOne == NULL || fileTwo == NULL)
	{
		fprintf(stderr, "Error al tratar de abrir el archivo es : %s\n", strerror(errno));
		exit(errno);
	}
	int size = arraySize(fileOne), lenght = arraySize(fileTwo);
	if (size != lenght)
	{
		printf("Los tamaños de los vectores no coincidem, por lo que no se puede realizar el producto punto.");
		exit(EXIT_FAILURE);
	}

	int remainder = size % arg;
	int numComputation = (size - remainder) / arg;
	rewind(fileOne);
	rewind(fileTwo);
	int *arrayOne = malloc(size * sizeof(int));
	int *arrayTwo = malloc(size * sizeof(int));
	int arrayPos = 0;

	for (int i = 0; i < size; i++)
	{
		fscanf(fileOne, "%d", &arrayOne[i]);
		fscanf(fileTwo, "%d", &arrayTwo[i]);
	}
	struct timeval start, end;
	gettimeofday(&start, NULL);

	pthread_t *threadHandler = (pthread_t *)malloc(arg * sizeof(threadHandler));
	Struct **threadArg = (Struct **)malloc(arg * sizeof(threadArg));
	for (int i = 0; i < arg; i++)
	{
		Struct *arg = (Struct *)malloc(sizeof(Struct));
		arg->firstArray = arrayOne;
		arg->seconArray = arrayTwo;
		arg->start = arrayPos;
		arg->numComputation = numComputation;
		arg->dotProduct = 0;

		if (remainder > 0)
		{
			arg->numComputation = arg->numComputation + 1;
			remainder--;
		}

		arrayPos += arg->numComputation;
		threadArg[i] = arg;
		pthread_t thread;
		threadHandler[i] = thread;
		if (pthread_create(&threadHandler[i], NULL, dotProduct, (void *)threadArg[i]))
		{
			fprintf(stderr, "Error while creating thread\n");
			exit(1);
		}
	}
	for (int i = 0; i < arg; i++)
	{
		void *return_value;
		if (pthread_join(threadHandler[i], &return_value))
		{
			fprintf(stderr, "Error while waiting for thread\n");
			exit(1);
		}
	}

	int multiDotProduct = 0;
	for (int i = 0; i < arg; i++)
	{
		multiDotProduct += threadArg[i]->dotProduct;
	}
	printf("Multi-threaded dotproduct: %d\n", multiDotProduct);
	free(arrayOne);
	free(arrayTwo);
	for (int i = 0; i < arg; i++)
	{
		free(threadArg[i]);
	}
	free(threadArg);
	free(threadHandler);
	gettimeofday(&end, NULL);
	long seconds = (end.tv_sec - start.tv_sec);
	long timeElapsed = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	printf("El resultado del producto punto es: %d\n", multiDotProduct);
	printf("El tiempo de ejecución fue de %ld segundos, o %ld microsegundos\n", seconds, timeElapsed);
	fclose(fileOne);
	return 0;
}

void *dotProduct(void *thisarg)
{
	Struct *arg = (Struct *)thisarg;
	for (int i = 0; i < arg->numComputation; i++)
	{
		arg->dotProduct += arg->firstArray[arg->start + i] * arg->seconArray[arg->start + i];
	}
}

int arraySize(FILE *file)
{
	int counter = 0;
	char c;
	while ((c = fgetc(file)) != EOF)
	{
		if (c == '\n')
		{
			counter++;
		}
	}
	return counter + 1;
}