#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <time.h>
#include "pwd.h"

void udea_pwd(int index){
    char route[500];
    if(index == 0){
        printf("%s\n", getcwd( route, -1 ));
    } else if(index == 1){
        pid_t son = fork();
        if(son < 0){
            printf("There's been a problem while creating the thread, try again\n");
        } else if (son == 0){
            printf("\n[1] %d\n",getpid());
            printf("%s\n", getcwd( route, -1 ));
        } 
    }
}