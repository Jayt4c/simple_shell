#include "shell.h"


char *_get_env(char *_env)
{
	extern char **environ;
	int x;
	char *s;

	x = 0;

	for (x = 0; environ[x]; x++)
	{
		s = strtok(environ[x], "=");
		if (strcmp(_env, s) == 0)
			return (strtok (NULL, "\n"));
		x++;
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

int path_handler(char *cmd)
{
    char *path, *cmd_path, ch;
	int x;

	path = malloc((strlen(_get_env("PATH")) + 5));

	if (!path)
		return (0);

	strcpy(path, (_get_env("PATH") + 5));
	for (x = 0; path; x++)
	{
		if (path[x] == '\0' || path[x] == ':')
		{
			ch = path[x];
			path[x] = '\0';
			cmd_path = malloc(strlen(path) + (x + 2));
			if (!cmd_path)
				return (0);
			strcpy(cmd_path, path);
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
				if (ch)
					path += (x + 1);
				free(cmd_path);
			}
		}
	}
	free(path);
	return (0);
}