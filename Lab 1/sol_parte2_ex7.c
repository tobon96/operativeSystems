#include <stdio.h>
#include <math.h>

int hallarDiscriminante(int a, int b, int c){
    int discriminante;
    discriminante = pow(b, 2) - (4*a*c);
    return discriminante;
}

void main(){
    int a, b, c, discriminanteRes, x1, x2;
    printf("Ingrese los valores a, b y c de la ecuación cuadrática, respectivamente: \n");
    scanf("%d %d %d", &a, &b, &c);
    discriminanteRes = hallarDiscriminante(a, b, c);
    
    if(discriminanteRes < 0){
        printf("La ecuación tiene raíces complejas conjugadas \n");
        double aux1, aux2;
        aux1 = (-b)/(2*a);
        aux2 = sqrt(-discriminanteRes) / (2*a);
        printf("La raíz uno es: %5.2ff i - %5.2ff j \n", aux1, aux2);
        printf("La raíz dos es: %5.2ff i + %5.2ff j \n", aux1, aux2);
    }else if(discriminanteRes == 0){
        printf("La ecuación tiene raíces reales e iguales (única solución) \n");
        x1 = (-b)/(2*a);
        x2 = x1;
        printf("Las raíces son: %d %d \n", x1, x2);
    }else if(discriminanteRes > 0){
        printf("La ecuación tiene raíces reales y distintas \n");
        x1 = (-b - sqrt(discriminanteRes))/(2*a);
        x2 = (-b + sqrt(discriminanteRes))/(2*a);
        printf("Las raíces son: %d %d \n", x1, x2);
    }
}