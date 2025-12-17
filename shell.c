#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *buffer;
	char *args[MAX_ARGS];
	int i;

	while (1)
	{
		/* Display prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		buffer = read_input();
		if (buffer == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (0);
		}

		/* Ignore lines with only spaces or tabs */
		i = 0;
		while (buffer[i] == ' ' || buffer[i] == '\t')
			i++;

		if (buffer[i] == '\0')
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

		/* Built-in exit (allowed even if not required) */
		if (strcmp(args[0], "exit") == 0)
		{
			free(buffer);
			exit(0);
		}

		execute_command(args);

		free(buffer);
	}

	return (0);
}
