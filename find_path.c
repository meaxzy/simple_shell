#include "shell.h"

/**
 *find_path: function that searches for the executable program
 *@cmd: the strings of arry
 *return:
 */

void find_Path(char **cmd) {
    char *path = getenv("PATH");
    char *token = strtok(path, ":");
    char path_buffer[1024];

    while (token != NULL) {
        snprintf(path_buffer, sizeof(path_buffer), "%s/%s", token, cmd[0]);
        if (is_exec(path_buffer)) {
            // Execute the command using execv
            execv(path_buffer, cmd);
            // If execv fails, perror and exit
            perror("execv");
            exit(1);
        }
        token = strtok(NULL, ":");
    }

    fprintf(stderr, "%s: command not found\n", cmd[0]);
    exit(1);
}
