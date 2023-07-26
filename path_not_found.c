#include "shell.h"

/**
 * path_not_found - if the path is not found
 * @first_arg: the first argument entered by the user
 * @commands: the list of arguments entered
 * @env: the list of environment variables
 *
 */

void path_not_found(char *first_arg, char **commands, char **env)
{
	int found = 0;
	char *path = getenv("PATH");
	char *path_dup = strdup(path); /* duplicate the PATH environment variable */
	char *token = strtok(path_dup, ":");

	while (token != NULL)
	{
		char command_path[MAX_PATH_LENGTH];
		int len = _strlen(token);

		strncpy(command_path, token, len);
		if (command_path[len - 1] != '/')
		{
			command_path[len] = '/';
			len++;
		}
		strcpy(command_path + len, first_arg);
		if (access(command_path, X_OK) == 0)
		{
			/* Found the first argument in the PATH */
			found = 1;
			if (execve(command_path, commands, env) == -1)
				perror("Command execution failed");
		}
		token = strtok(NULL, ":");
	}
	if (!found)
	{
		write(STDERR_FILENO, "Command '", 9);
		write(STDERR_FILENO, first_arg, _strlen(first_arg));
		write(STDERR_FILENO, "' not found\n", 12);
	}
		/*free_commands(commands);*/
		free(path_dup);
}
