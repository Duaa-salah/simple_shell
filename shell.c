#include "main.h"

void execdodo(char *cm);

void execdodo(char *cm)
{
	char *args[3];
	char *buffer = NULL;

		cm = strtok(buffer, " \n");
		args[0] = cm;
		args[1] = strtok(NULL, " \n");
		args[2] = NULL;
	
	execve(cm, args, NULL);
	write(2, "Error\n", 6);
	_exit(127);
}

/**
 * excola - entry point of fun
 * @cm: var pointer declare
 * @args: enviromment
 */
void excola(char *cm)
{
	int iscomExists;
	int ifnotcombutpath;
	int duaa;
	char *buffer = NULL;
	cm = strtok(buffer, " \n");

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
			execdodo(cm);
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
}
