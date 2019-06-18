#include <stdio.h>

int main(int argc)
{
    int in;
    int res;
    printf("Numero final (empezando de 1): ");
    scanf("%d", &in);
    for(int a = 1; a <= 10; a++){
        for(int b = 1; b <= in; b++){
            res = b * a;
            printf("%d x %d = %d, ", b, a, res);
        }
        printf("\n");
    }
    return 0;
}
