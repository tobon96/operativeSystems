#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <time.h>
#include "parser.h"
#include "time.h"

void udea_time(int index){
    time_t currentTime = time(NULL);
    if(index == 0){
        char *timeString = ctime(&currentTime); // Convirtiendo a formato de tiempo local
        printf("%s", timeString);
    } else if(index == 1){
        pid_t son = fork();
        if(son < 0){
            printf("There's been a problem while creating the thread, try again\n");
        } else if (son == 0){
            char *timeString = ctime(&currentTime); // Convirtiendo a formato de tiempo local
            printf("%s", timeString);
        } 
    }
}