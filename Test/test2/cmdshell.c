#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

/* Function to read a line of input from the user */
char* read_input() {
    char* line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}

/* Function to parse the input into separate arguments */
	char* token;	
	char** parse_input(char* line) {
	char** arguments = (char**)malloc(MAX_ARGUMENTS * sizeof(char*));
	
	if (!arguments)
	{
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
	}

    
    int index = 0;
    token = strtok(line, " \t\n"); /* Tokenize the line using spaces, tabs, and newlines */
    while (token != NULL) {
        arguments[index] = token;
        index++;
        token = strtok(NULL, " \t\n");
    }
    arguments[index] = NULL; // Null-terminate the argument list
    return arguments;
}

// Function to execute a command
void execute_command(char** arguments) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(arguments[0], arguments) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Forking error
        perror("Error forking");
    } else {
        // Parent process
    	wait(&status);
	}
}

int main() {
    char* line;
    char** arguments;

    printf("Simple Shell\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("> ");
        line = read_input();           // Read input from the user
        arguments = parse_input(line); // Parse the input into arguments

        if (arguments[0] == NULL) {
            // Empty command; prompt again
            free(line);
            free(arguments);
            continue;
        }

        if (strcmp(arguments[0], "exit") == 0) {
            // Exit the shell if the user types 'exit'
            free(line);
            free(arguments);
            break;
        } else if (strcmp(arguments[0], "cd") == 0) {
            // Change directory command
            if (arguments[1] == NULL) {
                // No directory provided; print an error
                fprintf(stderr, "SimpleShell: expected argument to 'cd'\n");
            } else {
                if (chdir(arguments[1]) != 0) {
                    perror("SimpleShell");
                }
            }
        } else if (strcmp(arguments[0], "ls") == 0) {
            // LS command
            execute_command(arguments);
        } else {
            // Other commands
            execute_command(arguments);
        }

        free(line);
        free(arguments);
    }

    return 0;
}

