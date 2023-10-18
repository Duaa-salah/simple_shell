#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

void execdodo(char *cm, char *buffer);
void excola(char *cm, char *buffer);
/**int cpath(char *cm);*/

int main()
{
	char *buffer = NULL;
	size_t bsize = 0;
	ssize_t len = 0;
	int isexit;
	char **env = environ;
	char *cm;
	/**int result;*/

	int is_interactive = isatty(STDIN_FILENO);

	while (1) 
	{
		if (is_interactive)
		{
			write(2, "#cisfun$ ", 9);
		}

		len = getline(&buffer, &bsize, stdin);
		        
		if (len == -1)
		{
			if (is_interactive)
			{
				write(2, "\n", 1);
			}
			break;
		}

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
			excola(cm, buffer);
		}

		/**else
		{
			result = cpath(cm);
			if (result == 1)
			{
				excola(cm, buffer);
			}
			else
			{
				write(2, "./hsh: 1: ", 11);
				write(2, cm, strlen(cm));
				write(2, ": not found\n", 11);
			}
		}*/
	}

	free(buffer);
	return (0);
}
