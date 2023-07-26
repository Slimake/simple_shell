#include "shell.h"

/**
 * get_line - reads the command line arguments entered by the user
 *
 * Return: the arguments read
 */

char *get_line()
{
	char *lineptr = NULL;
	size_t n = 0;

	if (getline(&lineptr, &n, stdin) == EOF) /* handles ctr+d */
	{
		free(lineptr);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}

	return (lineptr);
}
