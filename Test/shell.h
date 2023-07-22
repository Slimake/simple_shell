#ifndef SHELL_H
#define SHELL_H

extern char **environ;

#define CMDARGS_MAX 100



/*include Files*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>



/*Prototypes*/
int newLine(char c);
void _prompt(char *argv[]);


#endif /*SHELL_H*/
