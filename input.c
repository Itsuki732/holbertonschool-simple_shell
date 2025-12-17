#include "shell.h"

/**
 * read_input - reads a line from standard input
 *
 * Return: pointer to the input string, or NULL on failure or EOF
 */
char *read_input(void)
{
	char *buffer = NULL;
	size_t size = 0;

	if (getline(&buffer, &size, stdin) == -1)
	{
		free(buffer);
		return (NULL);
	}

	buffer[strcspn(buffer, "\n")] = '\0';
	return (buffer);
}
