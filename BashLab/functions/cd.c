#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <time.h>
#include <errno.h>
#include "cd.h"

void udea_cd(int index, char * route){
    if(index == 0){
        if (chdir(route) != 0)
        fprintf(stderr, "Could not change directory to %s: %s\n", route, strerror(errno));
    } else if (index == 1){
        pid_t son = fork();
        if(son < 0){
            printf("There's been a problem while creating the thread, try again\n");
        } else if (son == 0){
        if (chdir(route) != 0)
        fprintf(stderr, "Could not change directory to %s: %s\n", route, strerror(errno));
        }
    }
}