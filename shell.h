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
void execute_pipe_commands(char **commands, int num_commands);
void execute_child_process(char **args, const char *command, int input_fd, int output_fd);
char *_get_env(char *_env);
int path_handler(char *cmd);
char *_strtok(char* s, const char* del);
int _setenv(char *_env, char *value);
char *envname(char* str);

#endif
