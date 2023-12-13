#include "shell.h"

/**
* _get_env - Gets the environment variable
*
* @env: Environment variable will be returned
*
* Return: The value of an environment variable
*/

char* _get_env(char* _env)
{
	extern char** environ;
	char* s, * path;
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
				return (path);
			}
		}
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

int path_handler(char* cmd, char** args)
{
	char* path, * cmd_path, * iter, * tmp, ch;
	int x, len;

	x = 0;
	tmp = _get_env("PATH");
	if (!tmp)
		return (0);

	path = _strdup(tmp);
	if (!path)
		return (0);

	len = _strlen(path);
	iter = path;
	while (x < len)
	{
		if (iter[x] == '\0' || iter[x] == ':')
		{
			ch = iter[x];
			iter[x] = '\0';
			cmd_path = malloc(1024);
			if (!cmd_path)
				return (0);
			_strcpy(cmd_path, iter);
			_strcat(cmd_path, "/");
			_strcat(cmd_path, cmd);
			if (!access(cmd_path, X_OK))
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
	return (0);
}

