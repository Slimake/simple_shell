#include <stdio.h>
#include <stdarg.h>
#define prompt "$ "
int main()
{
        size_t n;
        char *lineptr;
        ssize_t cmd;
        printf("Entry Point\n");
        printf("%s", prompt);
        cmd = getline(&lineptr, &n, stdin);
        if (cmd == -1)
        {
        	perror("Error");
        }
        return 0;
}
