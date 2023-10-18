#include "main.h"
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * execdodo - Execute a command in
 * the current process or report not found
 * @cm: The command to execute
 * i - Initialize an index
 * @buffer: command buffer for error reporting
 * args - Array to store command and arguments
 */
void execdodo(char *cm, char *buffer)
{
	char *args[64];
	int i = 0;

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
/**
 * excola - Execute a command with
 * fork and waitpid
 * @cm: command to execute
 * @buffer: containing the command
 * iscomExists - Check if the command exists
 * ifnotcombutpath - Check if the command is
 * executable by its path
 * status - Variable to store the
 * status of a process
 * pid - Process ID of a child process
 * Return: 1 if the command exists, 0 otherwise
 */

void excola(char *cm, char *buffer)
{
	int iscomExists = access(cm, F_OK) == 0;
	int ifnotcombutpath = (cm[0] == '/') && (access(cm, X_OK) == 0);
	int status;

	if (iscomExists || ifnotcombutpath)
	{
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("Error in forking");
			return;
		}
		if (pid == 0)
			execdodo(cm, buffer);
		else
		{
			waitpid(pid, &status, 0);
			if (WIFSIGNALED(status))
				write(2, "terminated by signal.\n", 22);
		}
	}
	else
		fprintf(stderr, "./hsh: 1: %s: not found\n", cm);
}
