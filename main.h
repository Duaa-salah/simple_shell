#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

extern char **environ;

void excola(char *cm, char **args);
void execdodo(char *cm);


#endif
