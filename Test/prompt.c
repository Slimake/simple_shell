#include "shell.h"


void _prompt(char *argv[])
{
<<<<<<< HEAD
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
=======
	char *lineptr = NULL;
	size_t n = 0;/*bufsize*/
	pid_t pid;
	ssize_t cmd;
	char *prompt = "$ ";
	char *token;
	char **av;
	struct stat statbuff;
>>>>>>> 276dc7c5b259a604f1b62747939e2c35e457fc25
	char *env[] = {NULL};
	int i = 0;/*index*/

	while (1) 
	{	
		write(STDOUT_FILENO, prompt, 2);
<<<<<<< HEAD
		if (getline(&command, &n, stdin) == -1)
=======
		cmd = getline(&lineptr, &n, stdin);
		

		if (cmd == -1)
>>>>>>> 276dc7c5b259a604f1b62747939e2c35e457fc25
		{
			perror("Error");
			exit(0);
		}
<<<<<<< HEAD
	
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
=======
		
		av = (char**)malloc(CMDARGS_MAX * sizeof(char*));
		
		if (!av)
		{
			perror("Memeory alllocation error");
			exit(1);
		}




/* Tokenize lineptr using spaces, tabs and newline */
		token = strtok(lineptr, " \t\n");
		
		while (token != NULL)
		{
			av[i] = token;
			i++;
			token = strtok(NULL, " \t\n");
		}
		av[i] = NULL;
		return av;



/* check if pathname(token) exist */
		if (stat(av[0], &statbuff) == 0)
>>>>>>> 276dc7c5b259a604f1b62747939e2c35e457fc25
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
		       perror(av[0]);
	}
}
