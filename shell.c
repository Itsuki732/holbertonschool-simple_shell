#include "shell.h"

/**
 * main - entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{

	char *buffer;
	char *args[MAX_ARGS];
	shell_t shell;

	shell.last_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		buffer = read_input();
		if (buffer == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(shell.last_status);
		}

		if (buffer[0] == '\0')
		{
			free(buffer);
			continue;
		}

		parse_args(buffer, args);

		if (args[0] == NULL)
		{
			free(buffer);
			continue;
		}

		if (strcmp(args[0], "exit") == 0)
			builtin_exit(buffer, &shell);

		if (strcmp(args[0], "env") == 0)
		{
			builtin_env();
			free(buffer);
			continue;
		}

		execute_command(args, &shell);
		free(buffer);
	}
}
