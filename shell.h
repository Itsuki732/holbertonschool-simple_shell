#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_ARGS 1024

extern char **environ;

void execute_command(char **args);
char *find_path(char *command);

#endif /* SHELL_H */
