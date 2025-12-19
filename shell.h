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

/**
 * struct shell_s - shell context
 * @last_status: status of last executed command
 */
typedef struct shell_s
{
	int last_status;
} shell_t;


/* built-ins */
void builtin_exit(char *buffer, shell_t *shell);
void builtin_env(void);

/* autre fonction */
char *read_input(void);
void parse_args(char *buffer, char **args);
void execute_command(char **args, shell_t *shell);
char *find_path(char *command);

/* fonction du path.c */
char *check_command_path(char *command);
char *build_full_path(const char *dir, const char *command);
char *search_in_path(char *command);
char *find_path(char *command);

#endif /* SHELL_H */
