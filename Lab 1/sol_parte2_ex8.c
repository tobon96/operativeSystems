#include <stdio.h>
#include <stdlib.h>

int lanzamientoDeMoneda(){
  int randomNumber;      
  randomNumber = rand() % 2;
  return randomNumber;
}

int main() {
  int in, out, caras = 0, sellos = 0;
  srand((unsigned)time(NULL));
  printf("Ingrese el numero de veces que quiere lanzar la moneda: ");
  scanf("%d", &in);
  for(int i = 1; i <= in; i++){
    out = lanzamientoDeMoneda();
    if(out == 0){
      caras = caras + 1;
      printf("C");
    } else {
      sellos = sellos + 1;
      printf("S");
    }
  }  
  printf("\n# de Caras = %d ", caras);
  printf("# de Sellos = %d ", sellos);
  return out;
}