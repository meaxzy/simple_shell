#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;
int setenv_command(char *variable, char *value);
int unsetenv_command(char *variable);
char **incoming_command(int *sh);
void stripf(char *line);
char **tokenize_f(char **line);
int isexec_f(char **cmdname);
void find_pathf(char **cmdname);
void print_envf(void);
void exec_command(char **command, int *errs, int *exit_point);
void discharged_command(char **command);

#endif /*_MAIN_H_*/
