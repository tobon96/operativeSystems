#include <stdio.h>

int invertir(int numAInvertir){
    int aux, invert = 0;
    while (numAInvertir > 0){
        aux = numAInvertir % 10;
        invert = invert * 10 + aux;
        numAInvertir /= 10;
    }
    return invert;
}

void main(){
    int num, original, invertido;
    printf("Ingrese el numero: \n");
    scanf("%d", &num);
    original = num;
    invertido = invertir(num);

    printf("El numero dado es = %d\n", original);
    printf("Su inverso es  = %d\n", invertido);
}