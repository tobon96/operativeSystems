#include <stdio.h>

int esLetra(char ch) {
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        return 1;
    }
    return 0;
}

void volverMayuscula(char *ch) {
    if(*ch >= 'a' && *ch <= 'z'){
        *ch = *ch - 32;
    }    
}

void stringToMayuscula(char s[]) {
    char *ptr = s;
    int control;
    while(*ptr){
        control = esLetra(*ptr);
        if(control == 1){
            volverMayuscula(ptr);
        }       
        ptr++;
    }
}
/*********************************************************/
/*                     Funcion main                      */
/*********************************************************/
int main(void) {
    char cadena[100];
    while(1){
        printf("Entrada > ");
        fgets (cadena, 100, stdin);        
        stringToMayuscula(cadena);
        printf("Salida > %s", cadena);
    }
    return 0;
}