#include "shell.h"

extern char **environ; // External variable containing environment variables

void print_env(void) {
    for (char **env = environ; *env; env++) {
        printf("%s\n", *env);
    }
}
