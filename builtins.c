#include "shell.h"

/**
 * builtin_exit - handle exit built-in
 * @buffer: string containing the command line to release
 * @shell: pointer to the shell state structure
 */
void builtin_exit(char *buffer, shell_t *shell)
{
	int status;

	status = shell->last_status;
	free(buffer);
	exit(status);
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
