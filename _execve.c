#include "shell.h"

/**
 * _execve - execute a command
 * @commands: inputs read from the user
 * @env: list of environment variables
 */

void _execve(char **commands, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
		perror("Fork failed");

	if (pid == 0) /* child process */
	{
		/* Check if the the first argument contain / */
		char *first_arg = commands[0];
		int found = 0;
		/* checks if path is found */
		found = path_found(first_arg, commands, env);

		/* check if the command exits in directories in PATH */
		if (!found)
		{
			path_not_found(first_arg, commands, env);
		}
		exit(1);
	}
	else /* parent process */
	{
		wait(&status);
	}
}
