#include "shell.h"

/**
 * _strtok - Gets the string right before a delimeter
 * 
 * @s: Full string to be checked
 *
 * @del: the delimeter
 * 
 * Return: The string right before a delimeter
 */

<<<<<<< HEAD
char *_strtok(char* s, const char* del)
=======
char* _strtok(char* s, const char* del)
>>>>>>> cd36a457e21ed586b580e8577b90af23efeaf620
{
    static char* rem;
    char* tok;
    char* delim;

    if (s != NULL)
        rem = s;

    tok = rem;

    if (rem == NULL || *rem == '\0')
    {
        rem = NULL;
        return NULL;
    }

    delim = strpbrk(rem, del);

    if (delim != NULL)
    {
        size_t len = delim - rem;
        tok = malloc(len + 1);

        if (tok != NULL)
        {
            strncpy(tok, rem, len);
            tok[len] = '\0';
            rem = delim + 1;
        }
        else
            rem = NULL;
    }
    else
        rem = NULL;

    return (tok);
}