#ifndef _SHELL_H_
#define _SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


void display_prompt(void);
char **split_input(char *input);
int execute_command(char **args);
void free_args(char **args);
char *get_input(void);
void process_input(FILE *input);


#endif

