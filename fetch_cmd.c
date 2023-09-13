#include "shell.h"

/**
 * fetch_command - Reads and processes a command input from the user.
 *
 * @sh: Pointer to control the shell's operations (switch on/off)
 *
 * Return: An array of pointers representing command tokens,
 * or NULL if there's an issue.
 */
char **fetch_command(int *sh) {
    char **command = NULL;
    char *line = NULL;
    size_t size = 0;
    ssize_t read;

    if (isatty(STDIN_FILENO)) {
        printf("$ ");
        fflush(stdout); // Ensure the prompt is displayed immediately.
    }

    read = getline(&line, &size, stdin);

    if (read == -1) {
        if (isatty(STDIN_FILENO)) {
            printf("\n");
            fflush(stdout); // Ensure a newline is displayed after input.
        }
        free(line);
        *sh = 0;
        return NULL;
    }

    // Remove trailing newline character, if present.
    if (line[read - 1] == '\n') {
        line[read - 1] = '\0';
    }

    // Check for empty input.
    if (strlen(line) == 0) {
        free(line);
        return NULL;
    }

    // Tokenize the line into command arguments.
    command = tokenizef(line);

    return command;
}
