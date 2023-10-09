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
			 //call fun exc handle arduments 
		}

	}
free(buffer);
return 0;
}

void exc(char *cm, char **args)
{
	    
}
