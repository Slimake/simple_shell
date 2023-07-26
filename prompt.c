#include "shell.h"

/**
 * prompt - prompt the user for input
 * @env: the environment variables
 */

void prompt(char **env)
{
	char *lineptr;
	char **commands;
	char *former_dir = NULL;
	int exit_code = 0;

	/* Interactive mode */
	while (1)
	{
		/*if (isatty(STDIN_FILENO) != 0)*/
		write(STDIN_FILENO, "$ ", 2);
		lineptr = get_line(); /* Gets command from the command line */
		commands = command_parser(lineptr); /* Separate commands entered */
		if (commands[0] == NULL)
		{
			free(lineptr);
			free(commands);
			continue;
		}
			if (_strcmp(commands[0], "exit") == 0) /* exit command */
			{
				if (commands[1] != NULL)
					exit_code = _atoi(commands[1]);
				free(lineptr);
				free(commands);
				exit(exit_code);
			}
			else if (_strcmp(commands[0], "cd") == 0)
			{
				_cd(commands, lineptr, former_dir);
				continue;
			}
			else
				_execve(commands, env);
			free(lineptr);
			free(commands);
	}
	if (former_dir)
		free(former_dir);
}


