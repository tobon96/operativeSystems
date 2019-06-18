#include <stdio.h>

char cadena[100];
char cadenaAuxiliar[100];

char *obtenerSubcadena(char *array, int index) {
    int i = 0;
    while(*(array + index)){
        if(*(array + index) != 0){
            *(cadenaAuxiliar + i) = *(array + index); 
        }
        else{
            break;
        }
        array++;
        i++;
    }
    char *p3 = cadenaAuxiliar;
    return p3;
}

int main(int argc, char const *argv[]){
    int in;
    printf("Ingrese una cadena de caracteres: ");
    fgets (cadena, 100, stdin);
    char *p1 = cadena;
    printf("Ingrese el indice desde donde quiere imprimir la cadena: ");
    scanf("%d", &in);
    char *p2;
    p2 = obtenerSubcadena(p1, (in + 1));
    printf("%s",p2);    
    return 0;
}