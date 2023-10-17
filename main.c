#include "main.h"

extern char **environ;

void execdodo(char *cm);
void excola(char *cm);

int main()
{
	char *buffer = NULL;
	size_t bsize = 0;
	ssize_t len = 0;
	int isexit;
	char **env = environ;
	char *cm;

	while (1) 
	{
		write(2, "#cisfun$ ", 9);
		len = getline(&buffer, &bsize, stdin);
		        
		cm = strtok(buffer, " \n");
		isexit = strcmp(cm, "exit");

		if (len < 0)
		{
			write(2, "\nExit the shell.\n", 17);
			free(buffer);
			break;
		}

		if (isexit == 0)
		{
			free(buffer);
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
