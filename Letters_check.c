#include "shell.h"

/**
 * ltr_check - checks whether the string contains letters or not
 *
 * @s: string to be checked
 *
 * Return: 1 if success, 0 if failed
 **/

int ltr_check(char *s)
{
	int x;

	for (x = 0; s[x]; x++)
	{
		if ((s[x] >= 'a' && s[x] <= 'z') || (s[x] >= 'A' && s[x] <= 'Z'))
			return (1);
	}
	return (0);
}
