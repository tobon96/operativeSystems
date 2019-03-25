#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <time.h>
#include "functions/parser.h"
#include "functions/pwd.h"
#include "functions/clear.h"
#include "functions/time.h"
#include "functions/cd.h"

#define SIZE 50
#define SHELL "udea_shell>"

int entryFunction(char *function);
void externalFunction(int numOfParameters, char *items[]);
void internalFunction(int funtion, int background, int numOfParameters, char *items[]);
void exitFunction();

int main(){

  system("@cls||clear");
  printf("       __    __        __              _______                        __                    __   __\n");
  printf("      / /   / /       / /             / ___  /                       / /                   / /  / /\n");
  printf("     / /   / /       / /  ________   / /  / /            ________   / /        ________   / /  / /\n");
  printf("    / /   / /  _____/ /  / ____  /  / /  / /            / ______/  / /        / ____  /  / /  / /\n");
  printf("   / /   / /  / ___  /  / /___/ /  / /__/ /            / /_____   / /_____   / /___/ /  / /  / /\n");
  printf("  / /   / /  / /  / /  / ______/  / ___  /            /_____  /  / ____  /  / ______/  / /  / /\n");
  printf(" / /___/ /  / /__/ /  / /_____   / /  / /  _______   ______/ /  / /   / /  / /_____   / /  / /\n");
  printf("/_______/  /______/  /_______/  /_/  /_/  /______/  /_______/  /_/   /_/  /_______/  /_/  /_/\n");
  printf("Basic shell prompt for Operative Systems laboratory\n");
  printf("To see the manual, type 'udea_help'\n");
  char string[SIZE];
  char endString[] = "exit";
  char *folder;

  int end = 1;

  while(end != 0){
    char ** items;
    int numOfParameters;
    int background;
    folder = getcwd(folder, 200);
    printf("\E[1;3;4;32m");
    printf(SHELL);
    printf("\E[00m");
    printf(":");
    printf("\E[1;34m");
    printf("%s", folder);
    printf("\E[00m");
    printf("$");
    fgets (string, SIZE, stdin);
    fflush(stdin);
    end = strncmp(string, endString,strlen(endString));

    if(endString == 0){
      break;
    } else {
      numOfParameters = separaItems (string, &items, &background);
      if (numOfParameters > 0){
        int function = entryFunction(items[0]);
        if (background == 1 && function == -1) {
          externalFunction(numOfParameters, items);
        } else {
          internalFunction(function, background, numOfParameters, items);
        }  
      }      
    }
  }
  return 0;
}

int entryFunction(char *function){
  char *functions[] = {/*exit*/ "udea_exit",
                      /*pwd*/ "udea_pwd",
                      /*echo*/ "udea_echo",
                      /*clear*/ "udea_clear",
                      /*time*/ "udea_time",
                      /*cd*/ "udea_cd",
                      /*help*/ "udea_help"};
  int i;
  int size;
  for (i = 0; i < 7; i++)
  {
    size = strlen(functions[i]);
    if (strncmp(functions[i], function, size) == 0)
    {
      return (i + 1);
    }
  }
  return -1;
}

void internalFunction(int function, int background, int numOfParameters, char * items[]){
  switch (function){
    case 1:{
      exitFunction();
    }
    case 2:{
      if (background == 1){
        udea_pwd(background);    
      } else {
        udea_pwd(background);
      }
      break;
    }
    case 3:{
      if (background == 1){
        pid_t son = fork();
        if(son < 0){
          printf("There's been a problem while creating the thread, try again\n");
        }else if (son == 0){
          printf("\n[1] %d\n",getpid());
          int i;
          for(i = 1;i < numOfParameters; i++){
            printf("%s ",items[i]);
          }
          printf("\n");
        }     
      } else {
        int i;
        for(i = 1;i < numOfParameters; i++){
          printf("%s ",items[i]);
        }
        printf("\n");
      }
      break;
    }
    case 4:{
      if (background == 1){
        udea_clear(background);    
      } else {
        udea_clear(background);		          
      }
      break;
    }
    case 5:{
      if (background == 1){
        udea_time(background);    
      } else {
        udea_time(background);		          
      }
      break;
    }
    case 6:{
      if (background == 1){
        udea_cd(background, items[1]);    
      } else {
        udea_cd(background, items[1]);		          
      }
      break;
    }
    case 7:{
      printf("udea_shell entry functions:\n");
      printf("- Exit prompt: udea_exit\n");
      printf("- Get route to this directory: udea_pwd\n");
      printf("- Repeat receiving string: udea_echo\n");
      printf("- Clear promp: udea_clear\n");
      printf("- Get systen time: udea_time\n");
      printf("- Change directories: udea_cd\n");
      break;
    }
    default:{
      printf("Command not found, try again. For more help, type 'udea_help'\n");
      break;
    }    
  }
} 

void externalFunction(int numOfParameters, char *items[]){
	char route[strlen(items[0]) + 6];
	strcpy(route, "/bin/");
	strcat(route, items[0]);
	char *arg[numOfParameters + 1];
	int i;
	for(i=0; i<numOfParameters; i++){
    arg[i] = items[i];
  }		
	arg[i] = NULL;
	int result;
  pid_t son = fork();
  if(son < 0){
            printf("There's been a problem while creating the thread, try again\n");
  } else if(son == 0){
		result = execv(route, arg);
	  if (result == 1){
      exit(0);
	  }
  } else {
    int returnStatus;    
    waitpid(son, &returnStatus, 0);
  }
}

void exitFunction(){
  printf("udea_shell will close\n");
  exit(0);
}