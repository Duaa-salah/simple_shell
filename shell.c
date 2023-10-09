#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

void exc(char *cm, char **args);

int main ()
{
	char buffer[1024];
	size_t bsize = 0;

	while (1) 
	{
		printf("#cisfun$ ");
		getline(&buffer, &bsize, stdin);
		int isexit = strcmp(buffer, "exit\n");
		int isenv = strcmp(buffer, "env\n");
		
		if (isexit == 0)
		{
			break;
		}
		else if (isenv == 0)
		{
			// handle env
		}
		else 
		{
			char *comm = strtok(buffer, " \n");
			char *argum = strtok(NULL, " \n");
	
			char *arg[3];
			arg[0] = comm;
			arg[1] = argum;
			arg[2] = NULL;
			int iscomExists = access(cmd, F_OK) == 0;
			int ifnotcombutpath = (cmd[0] == '/') && (access(cmd, X_OK) == 0);

			if (iscomExists|| ifnotcombutpath)
			{
				exc(cm, args);
			}

		}

	}
free(buffer);
return 0;
}

void exc(char *cm, char **args)
{
	    
}
