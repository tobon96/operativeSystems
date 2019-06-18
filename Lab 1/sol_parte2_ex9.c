#include <stdio.h>
#include <stdlib.h>

int bucle(int en, int tra, int da){
    int trada = tra * da;
    while(en != trada){
        printf("No. Por favor intenta nuevamente: ");
        scanf("%d", &en);
    }
    printf("Muy bien");
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