#include <stdio.h>
#include <math.h>

int serieG(int a, int b){
    int res = 0;
    for(int i = 0; i <= b; i++){
        res = res + pow(a, i);
    }
    return res;
}

int main(int argc)
{
    int in, pot, out;
    printf("Ingrese los numeros de la base y exponente, respectivamente: ");
    scanf("%d %d", &in, &pot);
    out = serieG(in, pot);    
    printf("El resultado de la serie es: %d\n", out);      
    return 0;
}