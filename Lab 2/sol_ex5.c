#include <stdio.h>

double hallarMediana(double *array, int longitud){
    int mitad = (longitud)/2;
    double mediana = *(array + mitad);
    return mediana;
}

void swap(double *vec, int o, int d)
{
    double temp;
    temp = *(vec + d);
    *(vec + d) = *(vec + o);
    *(vec + o) = temp;
}

void burbuja(double *vectorAOrdenar, int tamano)
{
    int i, j;
    for (j=0; j<tamano; j++)
        for (i=0; i<tamano-1; i++)
            if(*(vectorAOrdenar + i) > *(vectorAOrdenar + i + 1))
                 swap(vectorAOrdenar, i, i+1);
}

int main(int argc, char const *argv[]){
    int nPosiciones;
    double mediana;
    printf("Por favor ingrese el numero de posiciones IMPAR del vector: \n");
    scanf("%d", &nPosiciones);
    while(nPosiciones % 2 == 0){
        printf("Por favor ingrese el numero de posiciones IMPAR del vector: \n");
        scanf("%d", &nPosiciones);
    } 
    double vector[nPosiciones];
    for(int i = 0; i < nPosiciones; i++){
        double auxiliar;
        printf("Por favor ingrese el numero de la posicion %d: \n", (i+1));
        scanf("%lf", &auxiliar);
        *(vector + i) = auxiliar;
    }
    burbuja(vector, nPosiciones);
    mediana = hallarMediana(vector, nPosiciones);
    printf("%lf \n", mediana);
    return 0;
}