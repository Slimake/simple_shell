#include "shell.h"

/**
 * set_pwd - set the an environment variable value
 * @wd: the second argument passed by the user
 *
 */

void set_pwd(char *wd)
{
	char curr_dir[MAX_PATH_LENGTH];

	if (getcwd(curr_dir, sizeof(curr_dir)) == NULL)
	{
		perror("Error");
		return;
	}
	setenv("PWD", wd, 2);
}
