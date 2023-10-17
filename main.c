#include "main.h"

extern char **environ;

void execdodo(char *cm);
void excola(char *cm);

int main(int argc, char *argv[])
{
	int d;
	char *buffer = NULL;
	int inter_mode = 1;

	if (argc > 1)
	{
		/**handle i/o redirection*/
		inter_mode = 0;
		for (d = 1; d < argc; d++)
		{
			excola(argv[d]);
		}

		free(buffer);
	}

	else
	{
		char *buffer = NULL;
	       	size_t bsize = 0;
		ssize_t len = 0;
		int isexit;
		char **env = environ;
		char *cm;

	while (inter_mode) 
	{
		write(2, "#cisfun$ ", 9);
		len = getline(&buffer, &bsize, stdin);
		        
		cm = strtok(buffer, " \n");
		isexit = strcmp(cm, "exit");

		if (len == -1)
		{
			write(2, "\nExit the shell.\n", 17);
			break;
		}

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

	}

	return (0);

}
