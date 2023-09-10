#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define STRTOK_BUFSIZE 1024
#define STRTOK_DELIM " \t\n"

extern char **environ;

void free_cmd(char **command);
int main(int argc, const char **argv);
char **fetch_cmd(int *active);
void print_env(void);
int is_exec(char **command);
void find_Path(char **command);
void exec_cmd(char **command, int err_count, int exit_status);

#endif
