#include "shell.h"

/**
 * path_handler - Handles the path that is passed to it
 * 
 * @directory: The path will be handled
 * 
 * Return: void 
*/

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

void path_handler(__attribute__((unused)) char *directory)
{
    extern char **environ;

    printf("%s", environ[1]);

    // DIR *d;
	// struct dirent *entry;
	// char *dPath = directory;

	// d = opendir(dPath);
	// if (d == NULL)
	// {
	// 	perror("opendir");
	// 	exit(1);
	// }

	// while ((entry = readdir(d)) != NULL)
	// {
	// 	printf("%s\n", entry->d_name);
	// }

	// if (entry == NULL)
	// {
	// 	perror("readdir");
	// 	exit(1);
	// }

	// closedir(d);
}