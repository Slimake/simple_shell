#include "shell.h"


void _prompt(char *argv[])
{
	pid_t pid;
	size_t n = 0;
	char *lineptr = NULL;
	ssize_t cmd;
	char *prompt = "$ ";
	char *token;
	char *av[] = {NULL, NULL};
	struct stat statbuff;
	char *env[] = {NULL};

	while (1) 
	{	
		write(STDOUT_FILENO, prompt, 2);
		cmd = getline(&lineptr, &n, stdin);
		if (cmd == -1)
		{
			perror("Error");
			exit(0);
		}
	
	
		token = strtok(lineptr, " \t\r\a\n");
		
	//	if ( == 2)
		
/* check if pathname(token) exist */
		if (stat(token, &statbuff) == 0)
		{
/* set first argument to be path */
			av[0] = token;

			pid = fork();
		
			if (pid == -1)
			{
/*check fork error*/
				perror("Fork Failed");
				exit(1);
			}

/*check if its a child/parent process.*/
			if (pid == 0)
			{
/*check execve return, if 0 (success), -1 (failed) */
				if(execve(av[0], av, env) == -1)
				{
					perror(av[0]);
					exit(1);
				}
			}
			if (pid > 0)
			{
				wait(NULL);
			}
		}
		else 
			perror(argv[0]);
	}
}
