#include "shell.h"

/***/


int _setenv(char* env, char* value)
{
	int x = 0, len;

	if (!env)
		return (-1);

	while (*environ)
	{
		if (strcmp(*environ, env) == 0)
		{
			idx = strlen(env) + 1;
			for (; value[x]; x++, idx++)
				*environ[idx] = value[x];
			*environ[idx] = '\0';
			break;
		}
		environ++;
	}
}