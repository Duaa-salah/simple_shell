#include "main.h"
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execdodo(char *cm)
{
	char *args[3];

	args[0] = cm;
	args[1] = strtok(NULL, " \n");
	args[2] = NULL;

	execve(cm, args, NULL);
	write(2, "Error\n", 6);
	_exit(127);
}

void excola(char *cm)
{
	int iscomExists = access(cm, F_OK) == 0;
	int ifnotcombutpath = (cm[0] == '/') && (access(cm, X_OK) == 0);
	int status;

	if (iscomExists || ifnotcombutpath)
	{
		pid_t pid = fork();
		if (pid == -1)
		{
			write(2, "Error in forking\n", 17);
		}
		if (pid == 0)
		{
			execdodo(cm);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
			{
				write(2, "Error\n", 6);
			}
			else if (WIFSIGNALED(status))
			{
				write(2, "terminated.\n", 12);
			}
		}
	}
}
