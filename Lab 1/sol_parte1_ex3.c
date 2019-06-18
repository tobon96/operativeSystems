#include <stdio.h>

int main(int argc)
{
    int in;
    printf("Ingrese el numero en la secuencia: ");
    scanf("%d", &in);
    for(int res = 1; res <= in; res++){
        for(int a = 1; a <= res; a++){
            if(res%2 == 0){
                if(a%2 == 0){
                    printf("1");
                } else {
                printf("0");
                }
            } else {
                if(a%2 == 0){
                    printf("0");
                }else {
                    printf("1");
                }
            }
        }   
        printf("\n");
    }     
    return 0;
}