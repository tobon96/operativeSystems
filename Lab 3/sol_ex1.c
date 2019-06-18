#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Estadistica {
    int caracteres;
    int palabras;
    int lineas;
    int espacios;
    int lMayusculas;
    int lMinusculas;
    int digitos;
} Estadistica;

int contarCaracteres(FILE *archivo){
    int c;
    int counter = 0;
    while ((c = getc(archivo)) != EOF){
        counter++;
    }
    return counter;
}

int contarLineas(FILE *archivo){
    int counter = 1;
    char ch;
    while ((ch = getc(archivo)) != EOF){
        if(ch == '\n'){
            counter++;
        }
    }
    return counter;
}

int contarMayusculas(FILE *archivo){
    int counter = 0;
    char ch;
    while ((ch = getc(archivo)) != EOF){
        if(ch >= 'A' && ch < 'Z'){
            counter++;
        }
    }
    return counter;
}

int contarMinusculas(FILE *archivo){
    int counter = 0;
    char ch;
    while ((ch = getc(archivo)) != EOF){
        if(ch >= 'a' && ch < 'z'){
            counter++;
        }
    }
    return counter;
}

int contarEspacios(FILE *archivo){
    int counter = 0;
    char ch;
    
    while ((ch = getc(archivo)) != EOF){
        if(ch == ' '){
            counter++;
        }
    }
    return counter;
}

int contarPalabras(FILE *archivo){
    int counter = 0;
    char ch;
    char aux = (char) archivo;
    while ((ch = getc(archivo)) != EOF){
        if((ch == ' ' || ch == '\n'  || (ch >= ',' && ch <= '.') || (ch >= ':' && ch <= ';')) && 
          ((aux >= 'A' && aux <= 'Z') || (aux >= 'a' && aux <= 'z'))){
            counter++;
        }
        aux = ch;
    }
    return counter;
}

int contarDigitos(FILE *archivo){
    int counter = 0;
    char ch;
    while ((ch = getc(archivo)) != EOF){
        if(ch >= '0' && ch < '9'){
            counter++;
        }
    }
    return counter;
}

char * generarNombre(char *fileName){
    printf("Obteniendo estadisticas... \n");
    printf("- %s --> generando reporte ", fileName);
    int c = 0;
    int longitud = strlen(fileName);
    char *nArchivo = malloc(sizeof(char)*20);
    
    while(c < longitud - 4){
        *(nArchivo + c) = *(fileName + c);
        c++;
    }
    strcat(nArchivo, "_stats.txt");
    return nArchivo;
}

int main(int argc, char *argv[]){
    
    Estadistica *estadistica = malloc(sizeof(Estadistica));
    FILE *file, *outFile;
    file = fopen(argv[1], "r+");
    if (!file) {               
        return 0;
    }

    estadistica->caracteres = contarCaracteres(file);
    //printf("Numero de caracteres = %d \n", estadistica->caracteres);

    fseek(file, 0, SEEK_SET);
    estadistica->palabras = contarPalabras(file);
    //printf("Numero de palabras = %d \n", estadistica->palabras);

    fseek(file, 0, SEEK_SET);
    estadistica->lineas = contarLineas(file);
    //printf("Numero de lineas = %d \n", estadistica->lineas);

    fseek(file, 0, SEEK_SET);
    estadistica->lMayusculas = contarMayusculas(file);
    //printf("Numero de mayusculas = %d \n", estadistica->lMayusculas);
    
    fseek(file, 0, SEEK_SET);
    estadistica->lMinusculas = contarMinusculas(file);
    //printf("Numero de minusculas = %d \n", estadistica->lMinusculas);

    fseek(file, 0, SEEK_SET);
    estadistica->espacios = contarEspacios(file);
    //printf("Numero de espacios = %d \n", estadistica->espacios);

    fseek(file, 0, SEEK_SET);
    estadistica->digitos = contarDigitos(file);
    //printf("Numero de espacios = %d \n", estadistica->espacios);

    fclose(file);
  
    char * nNombre = generarNombre(argv[1]);
    printf("%s \n", nNombre);

    outFile = fopen(nNombre, "w");

    fprintf(outFile, "Número de caracteres: %d\n", estadistica->caracteres);
    fprintf(outFile, "Número de palabras: %d\n", estadistica->palabras);
    fprintf(outFile, "Número de espacios: %d\n", estadistica->espacios);
    fprintf(outFile, "Número de líneas: %d\n", estadistica->lineas);
    fprintf(outFile, "Número de letras mayúsculas: %d\n", estadistica->lMayusculas);
    fprintf(outFile, "Número de letras minúsculas: %d\n", estadistica->lMinusculas);
    fprintf(outFile, "Número de digitos: %d\n", estadistica->digitos);
        
    fclose(outFile);

    free(nNombre);
    printf("Estadisticas culminadas \n");
    return 0;
}