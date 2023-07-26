#include "shell.h"

/**
 * _strcmp - Compares two string
 * @s1: first string
 * @s2: second string
 *
 * Return: 0(equal), 1(if s1 > s2), -1(if s1 < s2)
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
