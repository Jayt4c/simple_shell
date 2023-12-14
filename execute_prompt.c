#include "shell.h"

/**
 * execute_promptcommand - Execute the command entered at the prompt.
 *
 * @cmd: The command string to execute
 * @args: arguments
 *
 **/

void execute_promptcommand(char *cmd, char **args)
{
	pid_t id;
	int stat;

	id = fork();

	if (id == 0)
	{
		if (execve(cmd, args, environ) == -1)
			exit(2);
	}
	stat = 127;
	wait(&stat);
}
