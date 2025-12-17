#include "shell.h"

/**
 * find_path - find full path of a command
 * @command: command name
 *
 * Return: full path or NULL
 */
char *find_path(char *command)
{
	char *path, *copy, *dir, *full;
	struct stat st;

	if (command == NULL)
		return (NULL);

	if (strchr(command, '/'))
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	path = getenv("PATH");
	if (path == NULL || path[0] == '\0')
		return (NULL);

	copy = strdup(path);
	if (copy == NULL)
		return (NULL);

	dir = strtok(copy, ":");
	while (dir)
	{
		full = malloc(strlen(dir) + strlen(command) + 2);
		if (full == NULL)
			break;

		sprintf(full, "%s/%s", dir, command);

		if (stat(full, &st) == 0)
		{
			free(copy);
			return (full);
		}

		free(full);
		dir = strtok(NULL, ":");
	}

	free(copy);
	return (NULL);
}
