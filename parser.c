#include "shell.h"

/**
 * parse_args - splits input into arguments
 * @buffer: input line
 * @args: array of arguments
 */
void parse_args(char *buffer, char **args)
{
	int i = 0;
	char *token;

	token = strtok(buffer, " \t\n");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
}
