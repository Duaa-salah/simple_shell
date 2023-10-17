#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_COM 100

extern char **environ;

void execdodo(char *cm, char *buffer);
void excola(char *cm, char *buffer);

#endif /* MAIN_H */
