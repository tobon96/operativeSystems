#include <stdio.h>
#include <math.h>

int factorial(int n) {
  if (n > 0) {
    return n*factorial(n-1);
  }
  else {
    return 1;
  }
}

double secuencia(int a, int b){
    double res = 0;
    int aux = 0;
    for(int i = 1; i <= b; i++){
        if(i%2 == 0){
            res = res - pow(a, aux)/factorial(aux);
        } else {
            res = res + pow(a, aux)/factorial(aux);
        }
        aux = aux + 2;
    }
    return res;
}

int main(int argc)
{
    int in, term;
    double out;
    printf("Ingrese el valor de X y el numero de terminos para la secuencia, respectivamente: ");
    scanf("%d %d", &in, &term);
    out = secuencia(in, term);    
    printf("El resultado de la serie es: %ff\n", out);      
    return 0;
}