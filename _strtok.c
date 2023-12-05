#include "shell.h"

/**
 * _strtok - Gets the string right before a delimeter
 * 
 * @s: Full string to be checked
 *
 * @del: the delimeter
 * 
 * Return: The string right before a delimeter
 */

char *_strtok(char *s, char *del)
{
	static char *rem;
	char *tok;
	char *delim;
	
	rem = NULL;

	if (s)
	{
		rem = s;
	}
	tok = rem;
	delim = strchr(rem, *del);

	if (delim)
	{
		*delim = '\0';
		rem = delim + 1;
	}
	else
		rem = NULL;

	return (tok);
}