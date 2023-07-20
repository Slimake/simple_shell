#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void ls_handler() {
    printf("Handling ls command here...\n");
    // Implement your ls functionality using allowed functions and system calls
    // For example, you can use opendir(), readdir(), stat() or lstat(), etc.
    // Remember to replace this placeholder implementation with your actual code.
}

void _prompt() {
    size_t n = 0;
    char *lineptr = NULL;
    ssize_t cmd;
    char *prompt = "$ ";

    while (1) {
        write(STDOUT_FILENO, prompt, strlen(prompt));
        cmd = getline(&lineptr, &n, stdin);

        if (cmd == -1) {
            perror("Error");
            exit(0);
        } else {
            // Check if the command is "ls" and handle it
            if (strcmp(lineptr, "ls\n") == 0) {
                ls_handler();
                continue;
            }

            // Add other command handlers here...

            // For now, let's just print the entered command:
            printf("You entered: %s", lineptr);
        }
    }
    free(lineptr); // Free memory allocated by getline
}

int main() {
    _prompt();
    return 0;
}

