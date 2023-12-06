#include "shell.h"

/**
 * execute_child_process - Execute the execve
 *
 * @args: pointer to a pointer that holds arguments
 * @command: command entered
void free_args(char **args, int count);
 *
 **/
void execute_child_process(char **args, const char *command)
{

    /*if (strcmp(command, "/bin/ls") == 0) {
        if (execve("/bin/ls", args, NULL) == -1) {
            perror("execve failed");
            exit(EXIT_FAILURE);
        }
    } else {
        printout("Exiting command: ");
	    printout(command);
	    printout("\n");
        exit(EXIT_SUCCESS);
    }*/
	if (execve(command, args, NULL) == -1) {
		perror("execve failed ..");
		exit(EXIT_FAILURE);
	}
	else {
		printout("Exiting command: ");
		printout(command);
		printout("\n");
		exit(EXIT_SUCCESS);
	}

}

