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
	char* s, *path;
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
	char* path, * cmd_path, * iter, * tmp, ch;
	int x, len;

	if (cmd[0] == '/')
	{
		execute_promptcommand(cmd);
		return(1);
	}

	tmp = _get_env("PATH");
	if (!tmp)
		return (0);

	path = strdup(tmp);
	if (!path)
		return (0);


	len = strlen(path);
	iter = path;
	for (x = 0; x < len; x++)
	{
		if (iter[x] == '\0' || iter[x] == ':')
		{
			ch = iter[x];
			iter[x] = '\0';
			cmd_path = malloc(strlen(cmd) + (x + 2));
			if (!cmd_path)
				return (0);
			strcpy(cmd_path, iter);
			strcat(cmd_path, "/");
			strcat(cmd_path, cmd);
			if (!access(cmd_path, X_OK))
			{
				execute_promptcommand(cmd_path);
				free(path);
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
	printf("Command \"%s\" not found\n", _strtok(cmd, " "));
	free(path);
	execute_promptcommand(cmd);
	return (0);
}

