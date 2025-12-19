#include "shell.h"

/**
 * builtin_exit - handle exit built-in
 */
void builtin_exit(char *buffer)
{
	free(buffer);
	exit(last_status);
}

/**
 * builtin_env - handle env built-in
 */
void builtin_env(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
