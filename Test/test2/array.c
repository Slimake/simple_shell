#include <stdio.h>
#include <string.h>

int main()
{

int i = 0;
char j[] = {"Hello"};

for (; i < strlen(j); i++)

printf("%c.\n", j[i]);

return 0;
}
