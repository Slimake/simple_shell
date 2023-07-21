#include "shell.h"


void _prompt()
{
	pid_t pid;
	size_t n;
	char *lineptr;
	ssize_t cmd;
	char *prompt = "$ ";
	char *token;
	char *av[] = {"", NULL};
	struct stat statbuff;

	while (1) 
	{	
		write(STDOUT_FILENO, prompt, 2);
		cmd = getline(&lineptr, &n, stdin);
		if (cmd == -1)
		{
			perror("Error");
			exit(0);
		}

		token = strtok(lineptr, "\n");

		/* check if pathname(token) exist */
		if (stat(token, &statbuff) == -1)
		{
			perror("Error");
			exit(0);
		}
		else
		{
			/* set first argument to be path */
			av[0] = token;

			pid = fork();
			

		}
	}
}
