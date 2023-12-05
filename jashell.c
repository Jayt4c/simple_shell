#include "shell.h"

/**
 * main - display, read, and execute prompt command
 * Return: infinite loop
 **/

const char *filename;
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		filename =  argv[1];
		interactive_mode();
	}
	else if(argc == 1)
	{
		non_interactive_mode(filename);
	}
	else
	{
		printout("usage:");
		printout(argv[0]);
		printout("[script_file]\n");
		exit(EXIT_FAILURE);
	}

	return (0);
}
