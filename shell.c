#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

extern char **environ;

void exc(char *cm, char **args);
/**
 * main - entry point 
 * environ - variable pointer declare
 * global environment 
 *
 * Return - (0)
 */
int main ()
{
	char *buffer = NULL;
	size_t bsize = 0;

	while (1) 
	{
		printf("#cisfun$ ");
		getline(&buffer, &bsize, stdin);
		int isexit = strcmp(buffer, "exit\n");
		int isenv = strcmp(buffer, "env\n");
		int duaa;
		
		if (isexit == 0)
		{
			break;
		}
		else if (isenv == 0)
		{
			char **env = environ;
			while (*env != NULL)
			{
				write(2, *env, strlen(*env));
				write(2, "\n", 1);
				env++;
			}
		}
		else 
		{
			char *cm = strtok(buffer, " \n");
			char *args = strtok(NULL, " \n");
	
			char *args[3];
			args[0] = comm;
			args[1] = argum;
			arg2[2] = NULL;
			int iscomExists = access(cm, F_OK) == 0;
			int ifnotcombutpath = (cm[0] == '/') && (access(cm, X_OK) == 0);

			if (iscomExists|| ifnotcombutpath)
			{
				pid_t pid = fork();
				
				if (pid == 0)
				{
					exc(cm, args);
					write(2, "Error\n", 6);
					_exit(127);
				}
				else
				{
					waitpid(pid, &duaa, 0);
					if (WIFSIGNALED(duaa))
					{
						write(2, "terminanted.\n", 13);
					}

		}

	}
free(buffer);
return 0;
}

void exc(char *cm, char **args)
{
	    
}
