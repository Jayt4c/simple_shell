#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

void printout(const char *string);
void display_prompt(void);
void get_input(char *command, size_t size);
void execute_promptcommand(const char *command);
void execute_child_process(char **args, const char *command);

#endif
