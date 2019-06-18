#include <stdio.h>
#include <stdlib.h>

int correctas = 0, incorrectas = 0;

int bucle(int en, int tra, int da){
    int trada = tra * da, al;
    while(en != trada){
        al = rand() % 4;
        incorrectas ++;
        switch(al){
            case 0:
                printf("No. Por favor intenta nuevamente: ");
                break;
            case 1:
                printf("Incorrecto. Trata una vez mas: ");
                break;
            case 2:
                printf("No te rindas!: ");
                break;
            case 3:
                printf("No. Trata de nuevo: ");
                break;
        }        
        scanf("%d", &en);
    }
    al = rand() % 4;
    correctas ++;
        switch(al){
            case 0:
                printf("Muy bien");
                break;
            case 1:
                printf("Excelente!");
                break;
            case 2:
                printf("Buen trabajo!");
                break;
            case 3:
                printf("Sigue haciendolo bien!");
                break;
        }    
    return 0;
}

int main() {
    int in, ran, dom, parada = 1, nPreguntas, porcentaje;
    srand((unsigned)time(NULL));
    while(parada == 1){
        ran = rand() % 10;
        dom = rand() % 10;
        printf("¿Cuanto es %d veces %d?: ", ran, dom);
        scanf("%d", &in);
        in = bucle(in, ran, dom);
        printf("¿Desea continuar?, 1 = Si, 0 = No ");
        scanf("%d", &parada);
    }
    nPreguntas = correctas + incorrectas;
    porcentaje = (correctas * 100) / nPreguntas;
    printf("El porcentaje de respuestas acertadas es: %d %% \n", porcentaje);
    if(porcentaje < 75){
        printf("Por favor pídele ayuda al instructor\n");
    }
    return 0;
}