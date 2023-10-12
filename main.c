#include "main.h"
/**
 * main - entry point of fun
 * environ - var pointer declare
 * global enviromment
 * Return: jdekfmmfk
 */
int main (void)
{
	char *buffer = NULL;
	size_t bsize = 0;
	int isenv;
	int duaa;
	char **env;
	int iscomExists;
	int ifnotcombutpath;

	while (1) 
	{
		write(2, "#cisfun$ ", 9);
		getline(&buffer, &bsize, stdin);
		isenv = strcmp(buffer, "env\n");
		
		if (isenv == 0)
		{
			**env = environ;
			while (*env != NULL)
			{
				write(2, *env, strlen(*env));
				write(2, "\n", 1);
				env++;
			}
		}
		else 
		{
			iscomExists = access(cm, F_OK) == 0;
			ifnotcombutpath = (cm[0] == '/') && (access(cm, X_OK) == 0);

			if (iscomExists|| ifnotcombutpath)
			{
				pid_t pid = fork();

				if (pid == -1)
				{
					write(2, "Error in forking\n", 7);
				}
				if (pid == 0)
				{
					exc(cm, args);
				}
				else
				{
					waitpid(pid, &duaa, 0);
					if (WIFEXITED(duaa))
					{
						write(2, "Error\n", 6);
					}
					else if (WIFSIGNALED(duaa))
					{
						write(2, "terminanted.\n", 13);
					}

		}

	}
free(buffer);
return (0);
}

