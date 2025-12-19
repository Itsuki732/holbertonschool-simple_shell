#include "shell.h"

/**/

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

		if (strcmp(args[0], "exit") == 0)
			builtin_exit(buffer);

		if (strcmp(args[0], "env") == 0)
		{
			builtin_env();
			free(buffer);
			continue;
		}

		execute_command(args);
		free(buffer);
	}
}
