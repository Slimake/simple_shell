#include "shell.h"

/**
 * _atoi - converts string to integer
 * @str: the string to convert
 * Return: an integer
 */

int _atoi(const char *str)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    /* Skip spaces, newline and tab character */
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        i++;

    /* Check if + or - was typed in */
    if (str[i] == '+' || str[i] == '-')
	{
        sign = (str[i] == '+') ? 1 : -1;
        i++;
    }

    /* convert the string to digit */
    while (str[i] >= '0' && str[i] <= '9')
	{
        /* Check for overflow */
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)) {
            /* Handle overflow by returning the maximum or minimum integer value */
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        
        /* sum the digit */
        result = result * 10 + (str[i] - '0');
        i++;
    }

    /* Add the sign */
    return (result * sign);
}
