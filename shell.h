#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_ARGS 64

extern char **environ;

/* built-ins */
void builtin_exit(char *buffer);
void builtin_env(void);

/* autre fonction */
char *read_input(void);
void parse_args(char *buffer, char **args);
void execute_command(char **args);
char *find_path(char *command);

#endif /* SHELL_H */
