#include <stdio.h>

int multiplo(int a, int b){
    if(b%a == 0){
        return 1;
    }
    return 0;
}

int main(int argc)
{
    int in, mul, out;
    printf("Ingrese los numeros evaluar: ");
    scanf("%d %d", &in, &mul);
    out = multiplo(in, mul);
    if(out == 1){
        printf("%d es multiplo de %d\n", mul, in);
    } else {
        printf("%d no es multiplo de %d\n", mul, in);
    }       
    return 0;
}