#include <stdio.h>

int obtenerIndice(char *array, char ch) {
    int indice = -1;
    int aux = 0;
    while(*array){
        if(*array == ch){
            return aux;
        }
        aux++;
        array++;
    }
    return indice;
}

int main(int argc, char const *argv[]){
    char in;
    char cadena[100];;
    printf("Ingrese una cadena de caracteres: ");
    fgets (cadena, 100, stdin);
    printf("Ingrese el caracter que desea buscar en la cadena: ");
    scanf("%c", &in);
    int out = obtenerIndice(cadena, in);
    if(out == -1){
        printf("El caracter no se encuentra en la cadena\n");
    } else {
        printf("El caracter %c se encuentra en la posición %d de la cadena\n", in, out);
    }
    return 0;
}