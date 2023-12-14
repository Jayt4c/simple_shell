#include "shell.h"

/**
 * _strtok - Gets the string right before a delimeter
 *
 * @str: Full string to be checked
 *
 * @delimiter: the delimeter
 *
 * Return: The string right before a delimeter
 */

char *_strtok(const char *str, const char *delimiter)
{

	char *delim_pos, *substring;
	size_t substring_len;

	if (!str || !delimiter || !*str)
		return (NULL);

	delim_pos = strchr(str, *delimiter);

	if (!delim_pos)
		return (strdup(str));

	substring_len = delim_pos - str;

	substring = malloc(substring_len + 1);

	if (!substring)
		return (NULL);

	strncpy(substring, str, substring_len);
	substring[substring_len] = '\0';

	return (substring);
}
