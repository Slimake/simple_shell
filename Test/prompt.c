#include "shell.h"


void _prompt()
{
	size_t n;
	char *lineptr;
	ssize_t cmd;
	char *prompt = "$ ";

	while (1) 
	{	
	write(STDOUT_FILENO, prompt, 2);
	cmd = getline(&lineptr, &n, stdin);
	
		if (cmd == -1)
		{
			perror("Error");
			exit(0);
		}






	}



}
