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
void execute_promptcommand(const char *command);
char *_get_env(char* _env);
int path_handler(char *cmd);
<<<<<<< HEAD
char *_strtok(char* s, const char* del);
=======
char* _strtok(char* s, const char* del);
>>>>>>> cd36a457e21ed586b580e8577b90af23efeaf620
void execute_child_process(char **args, const char *command);
char* _get_env(char* _env);

#endif
