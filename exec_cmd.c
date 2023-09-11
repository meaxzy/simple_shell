#include "shell.h"

void exec_cmd(char **cmd, int err_count, int *exit_status) {
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {
        // This code is executed by the child process
        if (execvp(cmd[0], cmd) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        // This code is executed by the parent process
        waitpid(child_pid, &status, 0);
        if (WIFEXITED(status)) {
            *exit_status = WEXITSTATUS(status);
        }
    }
}
