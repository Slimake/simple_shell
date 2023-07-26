#include "shell.h"

/**
 * main - run the code
 * @argc: the number of arguments passed to main
 * @argv: the list of arguments passed
 * @env: the environment variables passed to main
 *
 * Return: 0 if success, -1 if fail
 */

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;

	prompt(env);

	return (0);
}
