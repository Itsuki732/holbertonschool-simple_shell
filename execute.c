#include "shell.h"

/**
 * execute_command - execute a command
 * @args: argument list
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;
	char *cmd;

	cmd = find_path(args[0]);
	if (cmd == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, args, environ);
		exit(1);
	}
	else if (pid > 0)
	{
		wait(&status);

		if (WIFEXITED(status))
			last_status = WEXITSTATUS(status);
		else
			last_status = 1;
	}

	free(cmd);
}
