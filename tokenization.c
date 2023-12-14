#include "shell.h"

/**
 * tokenize - Tokenizes the entered command
 *
 * @cmd: The command string to be seperated
 *
 * Return: Array of arguments
*/

/*
char** tokenize(char* cmd)
{
    size_t num_tokens = 10, i, x;
    char* tok, ** arr;

    if (!cmd)
        return (NULL);

    arr = malloc(sizeof(char*) * num_tokens);
    if (!arr)
        return (NULL);

    tok = strtok(cmd, " ");
    x = 0;

    while (tok)
    {
        if (x >= num_tokens)
        {
            num_tokens *= 2;
            arr = realloc(arr, sizeof(char*) * num_tokens);
            if (!arr)
            {
                free(arr);
                free(tok);
                return (NULL);
            }
        }
        arr[x] = malloc(_strlen(tok) + 1);
        if (!arr[x])
        {
            for (i = 0; i < x; i++)
                free(arr[i]);

            free(arr);
            free(tok);
            return (NULL);
        }
        _strcpy(arr[x], tok);
        x++;
        tok = strtok(NULL, " ");
    }
    free(tok);
    arr[x] = NULL;
    return (arr);
}
*/

void freeTokens(char** arr) {
    size_t i = 0;
    while (arr[i] != NULL) {
        free(arr[i]);
        i++;
    }
    free(arr);
}

char** tokenize(char* cmd) {

    char** arr;
    size_t x; 
    int i;

    x = strlen(cmd);

    arr = malloc(sizeof(char*) * x);
    if (arr == NULL)
        perror("not allocated mem\n");

    i = 0;
    arr[0] = strtok(cmd, " ");
    while (arr[i] != NULL)
    {
        i++;
        arr[i] = strtok(NULL, " ");
    }
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
    int i;

    if (!args) {
        return;
    }
    for (i = 0; args[i + 2]; ++i) {
        free(args[i]);
    }

    free(args);
}
