#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

/**
 * check_command_path - Checks if a command exists as a file.
 * @command: The command to check.
 *
 * Return: Pointer to a duplicated command path if it exists,
 *         NULL otherwise.
 */
char *check_command_path(char *command)
{
	struct stat st;

	return ((stat(command, &st) == 0) ? strdup(command) : NULL);
}

/**
 * build_full_path - Creates the full path of a command in a directory.
 * @dir: The directory to prepend.
 * @command: The command to append.
 *
 * Return: Pointer to the newly allocated full path, or NULL on failure.
 */
char *build_full_path(const char *dir, const char *command)
{
	size_t len = strlen(dir) + strlen(command) + 2;
	char *full = malloc(len);

	if (!full)
		return (NULL);

	sprintf(full, "%s/%s", dir, command);
	return (full);
}

/**
 * search_in_path - Searches for a command in the PATH directories.
 * @command: The command to search.
 *
 * Return: Pointer to the full path if found, NULL otherwise.
 */
char *search_in_path(char *command)
{
	char *path = getenv("PATH"), *copy, *dir, *full;
	struct stat st;

	if (!path || !*path)
		return (NULL);

	copy = strdup(path);
	if (!copy)
		return (NULL);

	for (dir = strtok(copy, ":"); dir; dir = strtok(NULL, ":"))
	{
		full = build_full_path(dir, command);
		if (!full)
			continue;

		if (stat(full, &st) == 0)
		{
			free(copy);
			return (full);
		}

		free(full);
	}

	free(copy);
	return (NULL);
}

/**
 * find_path - Finds the full path of a command.
 * @command: The command to locate.
 *
 * Return: Pointer to the full path if found, NULL otherwise.
 */
char *find_path(char *command)
{
	if (!command)
		return (NULL);

	if (strchr(command, '/'))
		return (check_command_path(command));

	return (search_in_path(command));
}
