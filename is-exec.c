#include "shell.h"

/**
 * is_exec: unction checks if a given command is an executable program
 *
 *@cmd:
 */

int is_exec(const char *cmd) {
    if (access(cmd, X_OK) == 0) {
        return 1; // Executable
    } else {
        return 0; // Not executable
    }
}
