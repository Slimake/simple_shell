#include "shell.h"


void _prompt(char *argv[])
{
	pid_t pid;
	char *token;
	char *pathname;
	struct stat statbuff;
	int i;
	int argc = 0;
	size_t n = 0;
	char *command = NULL;
	char *prompt = "$ ";
	char *av[] = {NULL, NULL};
	char *env[] = {NULL};

	while (1) 
	{	
		write(STDOUT_FILENO, prompt, 2);
		if (getline(&command, &n, stdin) == -1)
		{
			perror("Error");
			exit(0);
		}
	
		pathname = strtok(command, " \t\r\a\n");

		token = malloc(sizeof(char *));

		i = 0;
		while (pathname[i] != '\0')
		{
			token[i] = pathname[i];
			i++;
		}

		i = 0;
		while (token != NULL)
		{
			argc++;
			 argv[i] = strtok(NULL, " \t\r\a\n");
		}
		argv[i] = NULL;


		/*while (token != NULL)
		{
			argc++;
			token = strtok(NULL, " \t\r\a\n");
		}*/

		/* check if pathname(token) exist */
		if (stat(pathname, &statbuff) == 0)
		{
			/* set first argument to be path */
			av[0] = pathname;

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
