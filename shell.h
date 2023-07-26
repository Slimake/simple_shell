#ifndef SHELL_H
#define SHELL_H

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>

/* User defined macro */
#define INPUT_ARGS_MAX 100
#define MAX_PATH_LENGTH 1000

/* Function prototypes */
void prompt(char **env);
char *get_line();
char **command_parser(char *lineptr);
void _cd(char **commands, char *lineptr, char *former_dir);
int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
void _execve(char **commands, char **env);
int _atoi(const char *str);
void set_pwd(char *wd);
char **_strtok(char **str);
int path_found(char *first_arg, char **commands, char **env);
void path_not_found(char *first_arg, char **commands, char **env);

#endif /* SHELL_H */


