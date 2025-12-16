#include "shell.h"

/***/

void execute_command(char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execvp(args[0], args);
		perror("./shell");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}