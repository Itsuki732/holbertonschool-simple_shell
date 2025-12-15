#include "shell.h"

/***/

int main(void)
{
	char *buffer;
	char *args[MAX_ARGS];

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);

		buffer = read_input();
		if (!buffer)
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
		execute_command(args);

		free(buffer);
	}
}
