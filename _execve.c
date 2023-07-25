#include "shell.h"

/**
 * _execve - execute a command
 * @commands: inputs read from the user
 */

void _execve(char **commands, char **env)
{

	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
	}

	if (pid == 0) /* child process */
	{
		/* Check if the the first argument contain / */
		char *first_arg = commands[0];
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
		/* check if the command exits in directories in PATH */
		if (!found)
		{	
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
		exit(1);	
	}
	else /* parent process */
	{
		wait(&status); 
	}
}
