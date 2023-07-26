#include "shell.h"

/**
 * _strlen - gets the length of a string
 * @str: the string
 *
 * Return: length of the string
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}
