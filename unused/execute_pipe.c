#include "shell.h"

/**
 * execute_pipe_commands - execute
 * @command: command
 */

/*
void execute_pipe_commands(const char* command)
{
	int pipefd[2];
	pid_t pid;
	int status;
	char *command1, *command2;
	char command_copy[1024];

	strcpy(command_copy, command);
	command1 = strtok(command_copy, "|");
	command2 = strtok(NULL, "|");
	pipe(pipefd);
	pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execute_promptcommand(command1);
		perror("Exec failed");
		exit(EXIT_FAILURE);
	}

	close(pipefd[1]);
	pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		execute_promptcommand(command2);
		perror("Exec failed");
		exit(EXIT_FAILURE);
	}

	close(pipefd[0]);
	waitpid(pid, &status, 0);
}
*/