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



char* _strtok(const char* str, const char* delimiter)
{

	char* delim_pos, * substring;
	size_t substring_len;

	if (!str || !delimiter || !*str)
		return NULL;

	delim_pos = strchr(str, *delimiter);

	if (!delim_pos)
		return strdup(str);

	substring_len = delim_pos - str;


	substring = malloc(substring_len + 1);

	if (!substring)
		return (NULL);

	strncpy(substring, str, substring_len);
	substring[substring_len] = '\0';

	return (substring);
}

/*
char *_strtok(char *s, const char *del)
{
	static char *rem;
	char *tok,  *p;
	size_t len;

	if (s != NULL)
	{
		rem = s;
	}

	if (rem == NULL || *rem == '\0')
	{
		return (NULL);
	}

	p = _strpbrk(rem, (char *)del);

	if (p != NULL)
	{
		len = p - rem;
		tok = malloc(len + 1);
		if (!tok)
			return (NULL);

		strncpy(tok, rem, len);
		tok[len] = '\0';
		rem = p + 1;
	} else
	{
		len = strlen(rem);
		tok = malloc(len + 1);
		if (tok == NULL)
			return (NULL);
		_strcpy(tok, rem);
		rem = NULL;
	}
	return (tok);
}
*/
