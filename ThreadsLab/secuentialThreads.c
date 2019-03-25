#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <errno.h>

int dotProduct(int *arrayOne, int *arrayTwo, int size);
int arraySize(FILE *file);

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Numero incorrecto de argumentos\n");
		printf("Formato permitido: ./secuentialThreads <file1> <file2>\n");
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
	rewind(fileOne);
	rewind(fileTwo);
	int *arrayOne = malloc(size * sizeof(int));
	int *arrayTwo = malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		fscanf(fileOne, "%d", &arrayOne[i]);
		fscanf(fileTwo, "%d", &arrayTwo[i]);
	}
	struct timeval start, end;
	gettimeofday(&start, NULL);
	int product = dotProduct(arrayOne, arrayTwo, size);
	gettimeofday(&end, NULL);
	long seconds = (end.tv_sec - start.tv_sec);
	long timeElapsed = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	printf("El resultado del producto punto es: %d\n", product);
	printf("El tiempo de ejecución fue de %ld segundos, o %ld microsegundos\n", seconds, timeElapsed);
	free(arrayOne);
	free(arrayTwo);
	fclose(fileOne);
	return 0;
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

int dotProduct(int *arrayOne, int *arrayTwo, int size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		result += arrayOne[i] * arrayTwo[i];
	}
	return result;
}
