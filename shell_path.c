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
				free(s);
				return (path);
			}
			else
			{
				free(s);
				return (NULL);
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
 * Return: void
*/

int path_handler(char* cmd)
{
	char* path, * cmd_path, * iter, * tmp, ch, * args;
	int x, len;

	if (cmd[0] == '/')
	{
		execute_promptcommand(cmd);
		return(1);
	}
	tmp = _get_env("PATH");
	if (!tmp)
		return (0);

	path = _strdup(tmp);
	if (!path)
		return (0);

	if (_strchr(cmd, ' '))
	{
		args = malloc(_strlen(_strchr(cmd, ' ')) + 1);
		if (!args)
			return (0);
		_strcpy(args, _strchr(cmd, ' '));
	}

	len = _strlen(path);
	iter = path;
	for (x = 0; x < len; x++)
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
			if (_strlen(args))
				_strcat(cmd_path, _strtok(cmd, " "));
			else
				_strcat(cmd_path, cmd);

			if (!access(cmd_path, X_OK))
			{
				free(path);
				if (ltr_check(args))
				{
					_strcat(cmd_path, args);
					free(args);
				}
				execute_promptcommand(cmd_path);
				printout("-------------------------------------------------\n");
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
	printout("Command not found\n");
	free(path);
	execute_promptcommand(cmd);
	return (0);
}

