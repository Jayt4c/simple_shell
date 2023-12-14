#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>


extern char **environ;

void interactive_mode(void);
void printout(const char *string);
void display_prompt(void);
char **tokenize(char *cmd);
void execute_promptcommand(char *cmd, char **args);
char *_get_env(char *_env);
void cat(const char *file);
int path_handler(char* cmd, char** args);
int count_commands(const char *command);
char *_strtok(const char *str, const char* delimiters);
int path_handler(char *cmd, char **args);
char *_strtok(const char *str, const char *delimiter);
int _setenv(char *_env, char *value);
char *envname(char *str);
int ltr_check(char *s);
char *_strdup(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t x);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strpbrk(char *s, char *accept);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(const char *s1, const char *s2);
void free_args(char **args);
void free_args_1(char **args);
void free_args_2(char **args);
void lst_env(void);
int redirect(char* command);

#endif
