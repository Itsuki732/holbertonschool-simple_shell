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

/* input.c */
char *read_input(void);

/* parser.c */
void parse_args(char *buffer, char **args);

/* execute_command.c */
void execute_command(char **args);

/* path.c */
char *find_path(char *command);

#endif /* SHELL_H */
