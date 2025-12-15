#include "shell.h"

/***/

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	pid_t pid;

	while (1)
	{
		write(1, "#cisfun$ ", 9);

		if (getline(&line, &len, stdin) == -1)
		{
			write(1, "\n", 1);
			free(line);
			return (0);
		}

		line[strcspn(line, "\n")] = '\0';

		if (line[0] == '\0')
			continue;

		pid = fork();

		if (pid == 0)
		{
			char *argv[2];

			argv[0] = line;
			argv[1] = NULL;

			execve(line, argv, environ);
			perror("./shell");
			exit(1);
		}
		else
		{
			wait(NULL);
		}
	}
}
