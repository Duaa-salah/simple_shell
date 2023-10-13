#include "main.h"

void exec(char *cm);

void exec(char *cm)
{
	char *buffer = NULL;
	int isexit;
	char *args[3];

	isexit = strcmp(buffer, "exit\n");

	if (isexit == '\0')
	{
		break;
	}
	else
	{
		cm = strtok(buffer, " \n");
		args[0] = cm;
		args[1] = strtok(NULL, " \n");
		args[2] = NULL;
	}
	
	excola(cm, args);
	write(2, "Error\n", 6);
	_exit(127);
}

/**
 * excola - entry point of fun
 * @cm: var pointer declare
 * @args: enviromment
 */
void excola(char *cm, char **args)
{
	pid_t childp = fork();
	pid_t parentp;
	int st;

	ternormal = !WIFEXITED(st);
	tersignal = !WIFSIGNALED(st);

	if (childp == 0)
	{
		if (execvp(cm, args) == -1)
		{
			perror("Shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (childp < 0)
	{
		perror("Shell");
	}
	else
	{
		do {
			parentp = waitpid(childp, &st, WUNTRACED);
		} while (ternormal && tersignal);
	}
}
