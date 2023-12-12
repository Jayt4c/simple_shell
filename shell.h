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


void execute_file(const char *filename);
void non_interactive_mode(const char *filename);
void interactive_mode(void);
void printout(const char *string);
void display_prompt(void);
void get_input(char *command, size_t size);
void tokenize(const char *command, char **args);
void execute_promptcommand(const char *command);
void execute_pipe_commands(const char *command);
void execute_child_process(char **args, const char *command/*, int input_fd, int output_fd*/);
char *_get_env(char *_env);
void cat(const char *file);
int path_handler(char *cmd);
char *_strtok(char* s, const char* del);
int count_commands(const char *command);
char *_strtok(char *s, const char *del);
int _setenv(char *_env, char *value);
char *envname(char* str);
int ltr_check(char* s);
char* _strdup(char* str);
int _strlen(char* s);
char* _strcat(char* dest, char* src);


#endif
