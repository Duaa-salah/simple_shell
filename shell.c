#include "main.h"
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execdodo(char *cm, char *buffer)
{
	char *args[64];
	int i = 0;
	extern char **environ;

	args[i++] = cm;
	while ((cm = strtok(NULL, " \n")) != NULL)
	{
		args[i++] = cm;
	}
	args[i] = NULL;

	execve(args[0], args, environ);
	fprintf(stderr, "./hsh: 1: %s: not found\n", buffer);
	_exit(127);
}

void excola(char *cm, char *buffer)
{
	int iscomExists = access(cm, F_OK) == 0;
	int ifnotcombutpath = (cm[0] == '/') && (access(cm, X_OK) == 0);
	int status;
	/**char *path = getenv("PATH");
	int iscomExists;
	char pcp[1024];
	char pcomm[1024];
	char *bus = strtok(pcp, ":");

	if (path)
	{
		cstrcp(pcp, path);
		bus = strtok(pcp, ":");

		while (bus)
		{
			sprintf(pcomm, "%s%s", bus, cm);*/

	if (iscomExists || ifnotcombutpath)
	{
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("Error in forking");
			return;
		}
		if (pid == 0)
		{
			execdodo(cm, buffer);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFSIGNALED(status))
			{
				write(2, "terminated by signal.\n", 22);
			}
		}
		/**return;
	}
	bus = strtok(NULL, ":");
		}*/
	}
	else
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", cm);
	}
	/**fprintf(stderr, "./hsh: 1: %s: not found\n", cm);*/
}
