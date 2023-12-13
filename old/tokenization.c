#include "shell.h"

/**
 * tokenize - Tokenizes the entered command
 *
 * @cmd: The command string to be seperated
 *
 * Return: Array of arguments
*/

char** tokenize(char* cmd)
{
    size_t num_tokens = 15, i, x;
    char* tok, ** arr;

    arr = malloc(sizeof(char*) * num_tokens);
    if (!arr)
        return (NULL);

    tok = _strtok(cmd, " ");
    x = 0;

    while (tok)
    {
        if (x >= num_tokens)
        {
            num_tokens *= 2;
            arr = realloc(arr, sizeof(char*) * num_tokens);
            if (!arr) {
                free(arr);
                return (NULL);
            }
        }
        arr[x] = malloc(strlen(tok) + 1);
        if (!arr[x])
        {
            for (i = 0; i < x; i++)
                free(arr[i]);

            free(arr);
            return NULL;
        }
        strcpy(arr[x], tok);
        x++;
        tok = _strtok(NULL, " ");
    }
    arr[x] = NULL;
    return (arr);
}

/**
 * free_args - frees array of strings
 * 
 * @args: An array will be freed
 *
 * Return: void
 */

void free_args(char **args)
{
	size_t i;
	for (i = 0; i < 1; i++)
	{
		free(args[i]);
	}
	free(args);
}
