#include <stdio.h>

float comision(int entrada){
    float valor = (float)entrada;
    if(valor <= 20000 && valor >= 0){
        return valor * 0.05;
    } else if(valor > 20000 && valor <= 50000) {
        return 1000 + (valor - 20000)*0.07;
    } else if(valor > 50000){
        return 3100 + (valor - 50000)*0.1;
    }
    return 0;
}

int main(int argc)
{
    int in; 
    float out;
    printf("Ingrese el numero de ventas:");
    scanf("%d", &in);
    out = comision(in);
    printf("Se gana una comision de %10.3f\n", out);
    return 0;
}

