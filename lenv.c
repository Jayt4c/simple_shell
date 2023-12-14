#include "shell.h"

/**
 * lst_env - lists environment vars
 *
 * Return: void
*/

void lst_env(void)
{
	size_t x;

	for (x = 0; environ[x]; x++)
	{
		write(1, environ[x], _strlen(environ[x]));
		write(1, "\n", 1);
	}
}
