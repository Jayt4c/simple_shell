#include "shell.h"

/**
 * execute_pipe_commands - execute
 * @commands: command
 * num_command: number of commands
 */

void execute_pipe_commands(char **commands, int num_commands)
{
	int i, j;
	int *pipe_fds = malloc((num_commands - 1) * 2 * sizeof(int));
	pid_t *child_pid2 = malloc(num_commands * sizeof(pid_t));

	if (pipe_fds == NULL || child_pid2 == NULL)
	{
		perror("malloc failed for piping or child 2");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < num_commands - 1; i++)
	{
		if (pipe(pipe_fds + (i * 2)) == -1)
		{
			perror("file failed");
			exit(EXIT_FAILURE);
		}
	}

	for (i = 0; i < num_commands; i++)
	{
		child_pid2[i] = fork();

		switch (child_pid2[i])
		{
			case -1:
				perror("fork failed");
				exit(EXIT_FAILURE);
			case 0:
				if (i > 0)
				{
					dup2(pipe_fds[(i - 1) * 2], STDIN_FILENO);
				}

				if (i < num_commands - 1)
				{
					dup2(pipe_fds[i * 2 + 1], STDOUT_FILENO);
				}
				for (j = 0; j < (num_commands - 1) * 2; j++)
					close(pipe_fds[j]);

				execve(commands[i], commands + 1, NULL);
				perror("execve for child 2 failed");
				exit(EXIT_FAILURE);
			default:
				break;
		}
	}

	for (i = 0; i < num_commands - 1; i++)
	{
		close(pipe_fds[i]);
	}

	for (i = 0; i < (num_commands - 1) * 2; i++)
	{
		wait(NULL);
	}

	free(pipe_fds);
	free(child_pid2);
}
