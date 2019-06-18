#include <stdio.h>
#include <math.h>

int hallarDiscriminante(int a, int b, int c){
    int discriminante;
    discriminante = pow(b, 2) - (4*a*c);
    return discriminante;
}

void main(){
    int a, b, c, discriminanteRes;
    printf("Ingrese los valores a, b y c de la ecuación cuadrática, respectivamente: \n");
    scanf("%d %d %d", &a, &b, &c);
    discriminanteRes = hallarDiscriminante(a, b, c);
    if(discriminanteRes < 0){
        printf("La ecuación tiene raíces complejas conjugadas \n");
    }else if(discriminanteRes == 0){
        printf("La ecuación tiene raíces reales e iguales (única solución) \n");
    }else if(discriminanteRes > 0){
        printf("La ecuación tiene raíces reales y distintas \n");
    }
}