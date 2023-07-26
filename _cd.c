#include "shell.h"

/**
 * _cd - change directory
 * @commands: the list of arguments entered by the user
 * @lineptr: the commands entered by the user
 * @former_dir: the previous directory
 */

void _cd(char **commands, char *lineptr, char *former_dir)
{
	char *get_dir;
	char curr_dir[MAX_PATH_LENGTH];

	if (commands[1] == NULL || _strcmp(commands[1], "~")  == 0)
		get_dir = getenv("HOME");
	else if (_strcmp(commands[1], "-") == 0)
	{
		if (former_dir)/* checks if previous dir is not empty */
			get_dir = former_dir;
		else
		{
			write(STDERR_FILENO, "No previous directory\n", 22);
			free(lineptr);
			free(commands);
			return;
		}
	}
	else
		get_dir = commands[1];
		/* set current path as OLDPWD */
	if (getcwd(curr_dir, sizeof(curr_dir)) == NULL)
	{
		perror(commands[0]);
		free(lineptr);
		free(commands);
		return;
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
