#include "shell.h"
/**
 * _atoi - converts string to integer
 * @s: the string to convert
 * Return: an integer
 */
int _atoi(const char *s)
{
	int op = 1, result = 0, i = 0;

	/* Skip spaces, newline and tab character */
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	/* Check if + or - was typed in */
	if (s[i] == '-' || s[i] == '+')
	{
		op = (s[i] == '-') ? -1 : 1;
		i++;
	}
	/* convert the string to digit */
	while (s[i] >= '0' && s[i] <= '9')
	{
		/* Check for overflow */
		if (result > INT_MAX / 10 ||
				(result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
		{

			/* Handle overflow */
			return ((op == 1) ? INT_MAX : INT_MIN);
		}

		/* sum the digit */
		result = result * 10 + (s[i] - '0');
		i++;
	}

	/* Add the sign */
	return (result * op);
}
