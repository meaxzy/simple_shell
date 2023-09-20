#include "main.h"

/**
 * fetch_and_process_command - Reads and processes a user-input command.
 *
 * This function reads a command input from the user, processes it, and
 * returns an array of pointers representing command tokens. It also handles
 * special cases like the end of input or empty commands. If the shell's
 * interactive mode is enabled, it prompts the user with "$ ".
 *
 * @param sh: Pointer to control the shell's operations (switch on/off).
 *
 * Return: An array of pointers representing command tokens, or NULL if there's an issue.
 */
char **fetch_and_process_command(int *sh)
{
    char **command = NULL;
    char *line = NULL;
    size_t size = 0;
    ssize_t read;

    if (isatty(STDIN_FILENO))
    {
        printf("$ ");
    }

    read = getline(&line, &size, stdin);

    if (feof(stdin))
    {
        if (isatty(STDIN_FILENO))
            printf("\n");
        free(line);
        *sh = 0;
        return (NULL);
    }

    strip_whitespace(line);

    if (strlen(line) == 0 || read == -1)
    {
        free(line);
        return (NULL);
    }

    command = tokenize_line(&line);
    return (command);
}
