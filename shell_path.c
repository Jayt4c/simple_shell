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
	char *s, *path;
	int x, len;

	if (_env == NULL)
		return (NULL);
	for (x = 0; environ[x]; x++)
	{
		len = _strlen(_env);
		s = _strtok(environ[x], "=");
		if (strcmp(_env, s) == 0)
		{
			path = strdup(environ[x] + len);
			if (path)
			{
				if (s)
					free(s);
				return (path);
			}
		}
		free(s);
		s = NULL;
	}
	return (NULL);
}


/**
 * path_handler - checks whether the cmd path is existed or not
 *
 * @cmd: The command that user entered
 *
 * @args: array of arguments
 *
 * Return: 1 on success, 0 in failure
*/

int path_handler(char *cmd, char **args)
{
	char *path, *cmd_path, *iter, ch;
	int x = 0, len;

	path = _get_env("PATH");
	len = strlen(path);
	iter = path;
	for (; x < len; x++)
	{
		if (iter[x] == '\0' || iter[x] == ':')
		{
			ch = iter[x];
			iter[x] = '\0';
			cmd_path = malloc(512);
			if (!cmd_path)
			{
				free(path);
				return (0);
			}
			strcpy(cmd_path, iter);
			strcat(cmd_path, "/");
			strcat(cmd_path, cmd);
			if (access(cmd_path, X_OK) == 0)
			{
				free(path);
				execute_promptcommand(cmd_path, args);
				free(cmd_path);
				return (1);
			}
			else
			{
				free(cmd_path);
				if (ch)
					iter += (x + 1);
				len -= x;
				x = 0;
			}
		}
	}
	free(path);
	return (0);
}
