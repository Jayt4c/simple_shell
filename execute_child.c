#include "shell.h"

/**
 * execute_child_process - Execute the execve
 *
 * @args: pointer to a pointer that holds arguments
 * @command: command entered
void free_args(char **args, int count);
 *
 **/
void execute_child_process(char** args, const char* command)
{

<<<<<<< HEAD
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
=======
	if (execve(command, args, NULL) == -1) {
		perror("execve failed");
>>>>>>> cd36a457e21ed586b580e8577b90af23efeaf620
		exit(EXIT_FAILURE);
	}
	else {
		printout("Exiting command: ");
		printout(command);
		printout("\n");
		exit(EXIT_SUCCESS);
	}
<<<<<<< HEAD

=======
>>>>>>> cd36a457e21ed586b580e8577b90af23efeaf620
}

