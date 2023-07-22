#include <unistd.h>

int newLine(char c)
{
	write(1, &c, 1);
	return 0;
}
