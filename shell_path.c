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
	int x;
	if (_env == NULL)
		return (NULL);

	for (x = 0; environ[x]; x++)
	{
		char* s = strtok(environ[x], "=");
		if (s != NULL && strcmp(_env, s) == 0)
		{
			char* path = strtok(NULL, "\n");
			if (path != NULL)
			{
				return (path);
			}
			else
				return (NULL);
		}
	}
	return (NULL);
}


/**
 * path_handler - checks whether the cmd path is existed or not
 *
 * @cmd: The command that user entered
 *
 * Return: void
*/

int path_handler(char* cmd)
{
	extern char** environ;
	char* path, *cmd_path, *tmp, *freer, ch;
	int x, len;

	x = 0;

	tmp = _get_env("PATH");
	
	if (!tmp)
		return (0);
	
	path = malloc(strlen(tmp) + 1);
	
	if (!path)
		return (0);


	strcpy(path, (tmp));
	len = strlen(path);
	freer = path;

	for (; x < len; x++)
	{
		if (path[x] == '\0' || path[x] == ':')
		{
			ch = path[x];
			path[x] = '\0';
			cmd_path = malloc(strlen(cmd) + (x + 2));
			if (!cmd_path)
				return (0);
			strcpy(cmd_path, path);
			strcat(cmd_path, "/");
			strcat(cmd_path, cmd);
			if (!access(cmd_path, X_OK))
			{
				execute_promptcommand(cmd_path);
				path = freer;
				free(path);
				free(cmd_path);
				return (1);
			}
			else
			{
				free(cmd_path);
				if (ch)
					path += (x + 1);
				len -= x;
				x = 0;
			}
		}
	}
	path = freer;
	free(path);
	return (0);
}

