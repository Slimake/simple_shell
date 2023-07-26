#include "shell.h"

/**
 * prompt - Displays the shell prompt and handles user commands.
 *
 * @env: Array of strings containing the environment variables.
 *       Note: This function assumes NULL-terminated array of strings.
 *
 * Description:
 * This function is the main entry point for the shell. It creates an
 * interactive command-line interface, displaying the prompt symbol "$ ".
 * The function reads user commands, parses them, and executes the respective
 * built-in commands like "exit" and "cd". For other commands, it calls the
 * `_execve` function to execute external commands.
 *
 * Parameters:
 *   @env: The environment variables required for external command execution.
 *
 * Return: This function does not return normally, it terminates the program
 *         when the "exit" command is executed, or an error occurs.
 */

void prompt(char **env)
{
	char *lineptr;
	char **commands;
	char *former_dir = NULL;
	char curr_dir[MAX_PATH_LENGTH];
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
				char *get_dir;
				if (commands[1] == NULL || _strcmp(commands[1], "~")  == 0)
				{
					get_dir = getenv("HOME");
				}
				else if (_strcmp(commands[1], "-") == 0)
				{
					if (former_dir)/* checks if previous dir is not empty */
						get_dir = former_dir;
					else
					{
						write(STDERR_FILENO, "No previous directory\n", 22); 
						free(lineptr);
						free(commands);
						continue;
					}
				}
				else
				{
					get_dir = commands[1];
				}
				/* set current path as OLDPWD */
				if (getcwd(curr_dir, sizeof(curr_dir)) == NULL)
				{	
					perror(commands[0]);
					free(lineptr);
					free(commands);
					continue;
				}
				setenv("OLDPWD", curr_dir, 2);

				if (chdir(get_dir) == 0)
				{
					set_pwd(get_dir);
					if (former_dir)
						free(former_dir);
					former_dir = strdup(curr_dir);
				}
				else
					perror(commands[0]);
			}	
			else
			{
				_execve(commands, env);
			}

			free(lineptr);
			free(commands);	
		/*}
		else
		{
			Mode: Non-iteractive
			lineptr = get_line();
			commands = command_parser(lineptr);
			if (commands[0] != NULL)
				_execve(commands, env);

			free(lineptr);
			free(commands);
		}*/
	}
	if (former_dir)
		free(former_dir);
}
