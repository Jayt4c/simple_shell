#include "shell.h"

/**
 * envname - Gets the name an environment variable
 * 
 * @str: the variable its name will be extracted
 *
 * Return: Environment variable name*/


char* envname(char* str)
{
	char* ret;
	int x;

	for (x = 0; str[x] != '='; x++)
		ret[x] = str[x];

	ret[x] = '\0';

	return (ret);
}

int _setenv(char* _env, char* value)
{
	extern char** environ;
	char* tmp, * new;
	int x = 0, idx;

	if (_env == NULL)
		return (-1);

	idx = strlen(_env) + 1;

	new = malloc(idx + 1 + strlen(value));
	while (*environ != NULL)
	{
		tmp = malloc(strlen(envname(*environ)) + 1);
		if (!tmp)
			return (-1);
		strcpy(tmp, envname(*environ));
		if (strcmp(tmp, _env) == 0)
		{
			strcpy(new, _env);
			strcat(new, "=");
			strcat(new, value);
			*environ = new;
			free(tmp);
			printf("%s\n", *environ);
			return (0);
		}
		environ++;
	}
	return (-1);
}