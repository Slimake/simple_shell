#include "shell.h"

/**
 * path_found - check to see if a path exist
 * @first_arg: first argument in the list of commands passed
 * @commands: the list of arguments passed
 * @env: the list of environment variables
 * Return: 1 if path exist or 0 if it doesn't
 */

int path_found(char *first_arg, char **commands, char **env)
{
	int found = 0;
	int i;

	for (i = 0; first_arg[i] != '\0'; i++)
	{
		if (first_arg[i] == '/')
		{
			found = 1;
			if (access(first_arg, X_OK) == 0)
			{
				if (execve(first_arg, commands, env) == -1)
					perror("Command execution failed");
			}
			else
			{
				write(STDERR_FILENO, "Command '", 9);
				write(STDERR_FILENO, first_arg, _strlen(first_arg));
				write(STDERR_FILENO, "' not found\n", 12);
			}
			break;
		}
	}
	return (found);
}
