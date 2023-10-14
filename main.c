#include "main.h"
/**
 * main - entry point of fun
 * environ - var pointer declare
 * global enviromment
 * Return: jdekfmmfk
 */
void execdodo(char *cm);
void excola(char *cm);

int main()
{
	char *buffer = NULL;
	size_t bsize = 0;
	int isenv;
	char **env = environ;
	char *cm = strtok(buffer, " \n");
	int isexit = strcmp(buffer, "exit\n");

	while (1) 
	{
		write(2, "#cisfun$ ", 9);
		getline(&buffer, &bsize, stdin);
		isenv = strcmp(buffer, "env\n");
		execdodo(cm);

		buffer = (char *)malloc(bsize + 1);
		if (buffer == NULL)
		{
			perror("Memory allocation failed");
			exit(1);
		}

		 if (isexit == '\0')
	        {
		                break;
		}	
		else if (isenv == 0)
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

