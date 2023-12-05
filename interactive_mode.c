#include "shell.h"

void interactive_mode(void)
{
	char command[1024];

	for(;;)
	{
		display_prompt();
		get_input(command, sizeof(command));
		
		if (strncmp(command, "exit", 4) == 0)
		{
			printout("Exiting my shell...\n");
	/*	exit(EXIT_SUCCESS);*/
			break;
		}

		execute_promptcommand(command);
    }
}
