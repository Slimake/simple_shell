#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_ARGS 64
#define MAX_ARG_LEN 256

// Function to split the input command into arguments
void parse_input(char *input, char **args) {
    int i = 0;
    char *token = strtok(input, " \t\n");

    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }

    args[i] = NULL;
}

// Function to execute the command
void execute_command(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror(args[0]);
            _exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        int status;
        wait(&status);
    }
}

int main(void) {
    char input[MAX_ARG_LEN];
    char *args[MAX_ARGS];

    while (1) {
        printf("$ ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // End of input
        }

        // Remove the newline character from the input
        input[strcspn(input, "\n")] = '\0';

        parse_input(input, args);

        if (args[0] != NULL) {
            // Check if the user wants to exit
            if (strcmp(args[0], "exit") == 0) {
                break;
            }

            // Execute the command
            execute_command(args);
        }
    }

    return EXIT_SUCCESS;
}

