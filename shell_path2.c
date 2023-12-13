#include "shell.h"

/**
* _get_env - Gets the environment variable
*
* @_env: Environment variable will be returned
*
* Return: The value of an environment variable
*/

char *_get_env(char *_env)
{
	/*extern char **environ;*/
	char *s, *path;
	int x;

	if (_env == NULL)
		return (NULL);

	for (x = 0; environ[x]; x++)
	{
		s = _strtok(environ[x], "=");
		if (s != NULL && strcmp(_env, s) == 0)
		{
			path = _strtok(NULL, "\n");
			if (path)
			{
				free(s);
				return (path);
			}
		}
	}
	free(s);
	return (NULL);
}
