#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <time.h>
#include "clear.h"

void udea_clear(int index){
    if(index == 0){
        system("@cls||clear");
    } else if (index == 1){
        pid_t son = fork();
        if(son < 0){
            printf("There's been a problem while creating the thread, try again\n");
        } else if (son == 0){
        printf("\n[1] %d\n",getpid());
        system("@cls||clear");
        }
    }
}