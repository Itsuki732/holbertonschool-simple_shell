#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *args[1024];
	int i;

	while (1)
	{
		/* Prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			exit(0);
		}

		/* Ignore empty lines / spaces */
		i = 0;
		while (line[i] == ' ' || line[i] == '\t')
			i++;

		if (line[i] == '\n' || line[i] == '\0')
			continue;

		/* Parse arguments */
		i = 0;
		args[i] = strtok(line, " \t\n");
		while (args[i])
		{
			i++;
			args[i] = strtok(NULL, " \t\n");
		}

		if (args[0] == NULL)
			continue;

		/* Built-in exit */
		if (strcmp(args[0], "exit") == 0)
		{
			free(line);
			exit(0);
		}

		execute_command(args);
	}

	free(line);
	return (0);
}
