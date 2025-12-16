#include "shell.h"

/**
 * parse_args - splits the input buffer into arguments
 * @buffer: input string to parse
 * @args: array to store the parsed arguments
 *
 * Return: Nothing
 */
void parse_args(char *buffer, char **args)
{
	int i = 0;
	char *token = strtok(buffer, " ");

	while (token && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
