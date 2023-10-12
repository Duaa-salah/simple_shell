#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"


void exc(char *cm, char **args);

void exc(char *cm, char **args)
{
}

/**
 * excola - entry point of fun
 * @cm: var pointer declare
 * @args: enviromment
 */
void excola(char *cm, char **args)
{
	pid_t childp = fork();
	pid_t parentp;
	int st;

	ternormal = !WIFEXITED(st);
	tersignal = !WIFSIGNALED(st);

	if (childp == 0)
	{
		if (execvp(cm, args) == -1)
		{
			perror("Shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (childp < 0)
	{
		perror("Shell");
	}
	else
	{
		do {
			parentp = waitpid(childp, &st, WUNTRACED);
		} while (ternormal && tersignal);
	}
}
