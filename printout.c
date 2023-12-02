#include "shell.h"

void printout(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string))
}
