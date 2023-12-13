#include "shell.h"

/**
 * execute_promptcommand - Execute the command entered at the prompt.
 *
 * @command: The command string to execute
 *
 **/

void execute_promptcommand(char* cmd, char** args)
{
	pid_t id;
	int stat;

	id = fork();

	if (x == 0)
	{
		execve(p, arguments, environ);
		exit(0);
	}
	stat = 127;
	wait(&status);
	return;
}
