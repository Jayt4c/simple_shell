#include "shell.h"

/**
 * execute_pipe_commands - execute
 * @commands: command
 * num_command: number of commands
 */

void execute_pipe_commands(const char *command)
{
    int pipefd[2];
    pid_t pid;
    int status;
    char *command1;
	    char *command2;
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

        /* execute first command */
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

        /* execute second command */
        execute_promptcommand(command2);

        perror("Exec failed");
        exit(EXIT_FAILURE);
    }

    close(pipefd[0]);

    waitpid(pid, &status, 0);
}
