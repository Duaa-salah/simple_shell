#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

#define max_com 100
extern char **environ;
extern char *buffer;
void excola(char *cm);
void execdodo(char *cm);


#endif
