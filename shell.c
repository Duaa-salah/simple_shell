#include "main.h"

void execdodo(char *cm)
{
	char *args[3];

	args[0] = cm;
	args[1] = strtok(NULL, " \n");
	args[2] = NULL;

	execve(cm, args, NULL);
	write(2, "Error..\n", 8);
	_exit(127);
}

void excola(char *cm)
{
	/**int iscomExists = access(cm, F_OK) == 0;
	int ifnotcombutpath = (cm[0] == '/') && (access(cm, X_OK) == 0);*/
	int status;

	/**if (iscomExists || ifnotcombutpath)
	{*/
		pid_t pid = fork();
		if (pid == -1)
		{
			write(2, "Error in forking\n", 17);
			return;
		}
		if (pid == 0)
		{
			execdodo(cm);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFSIGNALED(status))
			{
				write(2, "terminated by signal.\n", 22);
			}
		}
	/**}*/
}
