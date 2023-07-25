#include "shell.h"

/**
 * command_parser - separate the list of arguments
 * @lineptr: the list of arguments
 *
 * Return: the separated list of arguments
 */

/*char **command_parser(char *lineptr)
{
	char *token;
	int i;
	char **commands;

	commands = malloc(sizeof(char *) * INPUT_ARGS_MAX);
	if (commands == NULL)
	{
		perror("Memory not allocated");
		exit(1);
	}*/

	/* Tokenize the list of arguments using the escape character */
	/*i = 0;
	token = strtok(lineptr, " \t\r\n");
	while (token != NULL)
	{
		commands[i] = token;
		token = strtok(NULL, " \t\r\n");
		i++;
	}
	commands[i] = NULL;*/ /* Argument list must be NULL terminated */

	/*return (commands);
}*/





char **command_parser(char *lineptr)
{
	char *token;
	int i;
	char **commands;

	commands = malloc(sizeof(char *) * _strlen(lineptr));
	if (commands == NULL)
	{
		perror("Memory not allocated");
		exit(1);
	}

	/* Tokenize the list of arguments using the escape character */
	i = 0;
	token = strtok(lineptr, " \t\r\n");
	while (token != NULL)
	{
		commands[i] = token;
		token = strtok(NULL, " \t\r\n");
		i++;
	}
	commands[i] = NULL; /* Argument list must be NULL terminated */

	return (commands);
}
