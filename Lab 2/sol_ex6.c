#include <stdio.h>

void ordenamientoShell(double *notasE, int tam){
    int intervalo; 
    intervalo = tam/2;
    while(intervalo > 0){
        for(int i = intervalo; i < tam; i++){
            int j = i - intervalo;
            while(j >= 0){
                int k = j + intervalo;
                if(*(notasE + j) <= *(notasE +k)){
                    j = -1;
                }
                else{
                    double temp;
                    temp = *(notasE + j);
                    *(notasE + j) = *(notasE + k);
                    *(notasE + k) = temp;
                    j -= intervalo;
                }
            }
        }
        intervalo = intervalo / 2;
    }
}

double hallarPromedio(double *vector, int longitud){
    double promedio = 0;
    for(int i = 0; i < longitud; i++){
        promedio = promedio + *(vector + i);
    }
    promedio = promedio / longitud;
    return promedio;
}

int main(int argc, char const *argv[]){
    int nEstudiantes;
    double mediaAsignatura, mediaEstudiante, mediaClase, notaE, *ptr;
    printf("Por favor ingrese el numero de estudiantes \n");
    scanf("%d", &nEstudiantes);
    double notasEstudiantesPorMateria[nEstudiantes][5]; 
    double mediasMaterias[5], mediasClase[5], notaEstudiante[5], notasEstudiantes[nEstudiantes];
    for(int i = 0; i < 5; i++){
        printf("MATERIA %d : \n", (i + 1));
        for(int j = 0; j < nEstudiantes; j++){
            double notaEstudiante;
            printf("Por favor ingrese la nota del estudiante %d de la materia %d \n", (j + 1), (i + 1));
            scanf("%lf", &notaEstudiante);
            ptr = &notasEstudiantesPorMateria[j][i];
            *ptr = notaEstudiante;
        }   
    }
    //Promedio por estudiante
    for(int k = 0; k < nEstudiantes; k++){
        for(int l = 0; l < 5; l++){
            ptr = &notasEstudiantesPorMateria[k][l];
            notaE = *ptr;
            *(notaEstudiante + l) = notaE; 
        }
        mediaEstudiante = hallarPromedio(notaEstudiante, 5);
        *(notasEstudiantes + k) = mediaEstudiante;
        printf("El promedio del estudiante %d es: %lf \n \n", (k+1), mediaEstudiante);
    }   
    //Promedio por materia
    for(int k = 0; k < 5; k++){
        for(int l = 0; l < nEstudiantes; l++){
            ptr = &notasEstudiantesPorMateria[l][k];
            notaE = *ptr;
            *(mediasMaterias + l) = notaE; 
        }
        mediaAsignatura = hallarPromedio(mediasMaterias, nEstudiantes);
        *(mediasClase + k) = mediaAsignatura;
        printf("El promedio de la materia %d es: %lf \n \n", (k+1), mediaAsignatura);
    }
    //Promedio clase
    mediaClase = hallarPromedio(mediasClase, 5);
    printf("El promedio de la clase es: %lf \n \n", mediaClase);
    ordenamientoShell(notasEstudiantes, nEstudiantes);
    printf("Las notas ordenadas son: \n");
    //Notas ordenadas
    int aux = nEstudiantes;
    while(aux > 0){
        printf("%lf \n", *(notasEstudiantes + (aux-1)));
        aux--;
    }
    return 0;
}