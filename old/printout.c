#include "shell.h"

/**
 * printout - prints to the standard file number
 * @string: takes in a strin to print
 **/

void printout(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
