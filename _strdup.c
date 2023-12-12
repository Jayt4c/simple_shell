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

/**
 * _strlen - function calculates the length of a string
 *
 * @s: The string will be calculated
 *
 * Return: The length of the string input
*/

int _strlen(char* s)
{
	int count = 0;

	while (*(s + count) != 0)
		count++;

	return (count);
}

/**
 * _strcat - concatenates two strings
 *
 * @dest: The destination that src will be added to
 *
 * @src: The string will be added
 *
 * Return: concatenated string
*/

char* _strcat(char* dest, char* src)
{
	int i = 0;
	int y = 0;

	while (dest[i] != '\0')
		i++;

	while (src[y] != '\0')
	{
		dest[i++] = src[y++];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strchr - locates character in string
 *
 * @s: The string will be checked
 *
 * @c: The character will be located
 *
 * Return: The string after locating the character
*/

char* _strchr(char* s, char c)
{
	int x = 0;

	while (s[x] >= '\0')
	{
		if (s[x] == c)
		{
			return (s + x);
		}
		x++;
	}
	return (NULL);
}


/**
 * _strcpy - copies the string pointed to by src, including the
 * terminating null byte (\0), to the buffer pointed to by dest
 *
 * @dest: The destination the string will be copied to
 *
 * @src: The string will be copied
 *
 * Return: The string that has been copied
*/


char* _strcpy(char* dest, char* src)
{
	int x = -1;

	do {
		x++;
		dest[x] = src[x];
	} while (src[x] != '\0');

	return (dest);
}