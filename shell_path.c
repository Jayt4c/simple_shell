#include "shell.h"

/**
* _get_env - Gets the environment variable
*
* @env: Environment variable will be returned
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
				if(s)
					free(s);
				return (path);
			}
		}
		free(s);
	}
	return (NULL);
}


/**
 * path_handler - checks whether the cmd path is existed or not
 *
 * @cmd: The command that user entered
 *
 * Return: 1 on success, 0 in failure
*/

int path_handler(char *cmd, char **args)
{

	char* path, * cmd_path, * iter, * tmp, ch;
	int x, len;

	x = 0;

	tmp = _get_env("PATH");
	if (!tmp)
		return (0);
	path = strdup(tmp);
	if (!path)
		return (0);

	free(tmp);

	len = strlen(path);
	iter = path;
	while (x < len)
	{
		if (iter[x] == '\0' || iter[x] == ':')
		{
			ch = iter[x];
			iter[x] = '\0';
			cmd_path = malloc(1024);
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
		x++;
	}
	free(path);
	return (0);
}
