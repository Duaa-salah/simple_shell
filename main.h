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
int cpath(char *cm);
size_t cstrlen(char *dstrl);
void cstrcp(char *dest, char *src);

#endif /* MAIN_H */
