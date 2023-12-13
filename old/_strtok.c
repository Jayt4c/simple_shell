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

char* _strtok(char* s, const char* del) {
    static char* rem;
    char* tok, * p;
    size_t len;

    if (s != NULL) {
        rem = s;
    }

    if (rem == NULL || *rem == '\0') {
        return NULL;
    }

    p = _strpbrk(rem, (char *)del);

    if (p != NULL) {
        len = p - rem;
        tok = malloc(len + 1);

        if (tok == NULL) {
            return NULL; 
        }

        _strncpy(tok, rem, len);
        tok[len] = '\0';
        rem = p + 1;
    }
    else {
        len = strlen(rem);
        tok = malloc(len + 1);

        if (tok == NULL) {
            return NULL; 
        }

        _strcpy(tok, rem);
        rem = NULL;
    }

    return (tok);
}
