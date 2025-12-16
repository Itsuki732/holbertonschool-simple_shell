
#include "shell.h"

/***/

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
