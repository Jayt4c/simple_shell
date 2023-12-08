#include "shell.h"

/**
 * envname - Gets the name an environment variable
 * 
 * @str: the variable its name will be extracted
 *
 * Return: Environment variable name
*/


char* envname(char* str)
{
	char *ret;
	int x;

	for (x = 0; str[x] != '='; x++)
		ret[x] = str[x];

	ret[x] = '\0';

	return (ret);
}

/**
 * _setenv - Sets environment variable to a specific value
 *
 * @_env: the name of an environment variable
 *
 * @value: the value of an environment variable
 *
 * Return: 0 if succeed, -1 if failed
*/

int _setenv(char *_env, char *value)
{
	extern char **environ;
	int new_len;
	char *updt, **tmp;

	if (_env == NULL || value == NULL)
		return (-1);

	new_len = strlen(_env) + strlen(value) + 2;
	tmp = environ;

	while (*environ)
	{
		if (!strncmp(*environ, _env, strlen(_env)))
		{
			updt = malloc(new_len);
			if (!updt)
				return (-1);
			strcpy(updt, _env);
			strcat(updt, "=");
			strcat(updt, value);
			strcpy(*environ, updt);
			environ = tmp;
			free(updt);
			return (0);
		}
		environ++;
	}
	*environ = malloc(new_len);
	if (!*environ)
		return (-1);
	strcpy(*environ, _env);
	strcat(*environ, "=");
	strcat(*environ, value);
	environ = tmp;

	return (0);
}