#include <stdio.h>
#include <stdlib.h>

int bucle(int en, int tra, int da){
    int trada = tra * da, al;
    while(en != trada){
        al = rand() % 4;
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
  int in, ran, dom, parada = 1;
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
  return 0;
}