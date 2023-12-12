#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 *
 * @str: The string will be copied
 *
 * Return: A pointer to allocated memory cantains the string copy
 */


char *_strdup(char *str)
{
	int x, len = 0;
	char *ch;

	if (str == NULL)
		return (NULL);

	while (*str++ != '\0')
	{
		len++;
	}
	str -= (len + 1);

	ch = malloc(len + 1);

	if (ch == NULL)
		return (NULL);

	for (x = 0; x <= len; x++)
	{
		ch[x] = *str++;
	}

	return (ch);
}
