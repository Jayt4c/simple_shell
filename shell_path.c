#include "shell.h"

/**
 * path_handler - Handles the path that is passed to it
 * 
 * @directory: The path will be handled
 * 
 * Return: void 
*/

void path_handler(char *directory)
{
    DIR *d;
	struct dirent *entry;
	char *dPath = directory;

	d = opendir(dPath);
	if (d == NULL)
	{
		perror("opendir");
		exit(1);
	}

	while ((entry = readdir(d)) != NULL)
	{
		printf("%s\n", entry->d_name);
	}

	if (entry == NULL)
	{
		perror("readdir");
		exit(1);
	}

	closedir(d);
}