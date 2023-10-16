#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

void execdodo(char *cm);
void excola(char *cm);

int main()
{
	char *buffer = NULL;
	size_t bsize = 0;
	int isexit;
	char **env = environ;
	char *cm;

	while (1) 
	{
		write(2, "#cisfun$ ", 9);
		getline(&buffer, &bsize, stdin);
		        
		cm = strtok(buffer, " \n");
		isexit = strcmp(cm, "exit");

		if (isexit == 0)
		{
			break;
		}
		else if (strcmp(cm, "env") == 0)
		{
			while (*env != NULL)
			{
				write(2, *env, strlen(*env));
				write(2, "\n", 1);
				env++;
			}
		}
		else
		{
			excola(cm);
		}
	}

	free(buffer);
	return (0);
}
