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

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		buffer = read_input();
		if (buffer == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			return (0);
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

		/* built-in exit */
		if (strcmp(args[0], "exit") == 0)
		{
			free(buffer);
			exit(0);
		}

		/* built-in env */
		if (strcmp(args[0], "env") == 0)
		{
			int i = 0;

			while (environ[i])
			{
				write(STDOUT_FILENO, environ[i],
				      strlen(environ[i]));
				write(STDOUT_FILENO, "\n", 1);
				i++;
			}
			free(buffer);
			continue;
		}

		execute_command(args);
		free(buffer);
	}
}
