#include "shell.h"

/**
 * _strncmp - compares 2 strings to a specific index
 *
 * s1: The first string to compare
 *
 * s2: The second string to compare
 *
 * Return: 0 if they are equal, or the difference between them if
 * they're not
*/


int _strncmp(char* s1, char* s2, size_t x)
{
	size_t i;
	int diff;

	if (s1 == NULL || s2 == NULL || x == 0) {
		return (-1);
	}
	for (i = 0; i < x; ++i) {
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (diff != 0 || s1[i] == '\0' || s2[i] == '\0') {
			return (diff);
		}
	}
	return (0);
}

/**
 * _strpbrk - searches a string for any of a set of bytes
 *
 * @s: The string will be trimmed if the searched byte were found
 *
 * @accept: The bytes the function will search for
 *
 * Return: The trimmed value if the bytes were found
 * and NULL if not
*/

char* _strpbrk(char* s, char* accept)
{
	int x = 0;
	int y;

	if (s == NULL || accept == NULL)
		return (NULL);

	while (s[x] != '\0')
	{
		for (y = 0; accept[y] != '\0'; y++)
		{
			if (s[x] == accept[y])
			{
				return (s + x);
			}
		}
		x++;
	}
	return (NULL);
}

/**
 * _strncpy - copy a string
 *
 * @dest: The destination that the string will be copied to
 *
 * @src: The string will be copied
 *
 * @n: The length of chars will be copied
 *
 * Return: copied string
*/

char* _strncpy(char* dest, char* src, int n)
{
	int y;

	for (y = 0; y < n && src[y] != '\0'; y++)
	{
		*(dest + y) = *(src + y);
	}
	while (y < n)
	{
		dest[y] = '\0';
		y++;
	}
	return (dest);
}

/**
 * _strcmp -  compares two strings
 *
 * @s1: The first string will be compared
 *
 * @s2: The second string will be compared
 *
 * Return: The difference between first two different chars
*/

int _strcmp(const char* s1,const char* s2)
{
	int cmp = 0;
	int x = 0;

	while (s1[x] != '\0')
	{
		if (s1[x] != s2[x])
		{
			cmp = s1[x] - s2[x];
			break;
		}
		x++;
	}
	return (cmp);
}
