#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - entry point
 * buffer - Stores input line from the user
 * @cm: command to execute
 * @buffer: command buffer
 * bsize - size of the buffer
 * len - length of the input line
 * isexit - indicating the user
 * exit the shell
 * env - environment variables
 * cm - command to execute
 * is_interactive - indicating interactive mode
 *
 * Return: 0
 */

void execdodo(char *cm, char *buffer);
void excola(char *cm, char *buffer);

int main(void)
{
	char *buffer = NULL;
	size_t bsize = 0;
	ssize_t len = 0;
	int isexit;
	char **env = environ;
	char *cm;

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
	}

	free(buffer);
	return (0);
}
