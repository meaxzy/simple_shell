#include “shell.h”

char **fetch_cmd(int *active) {
    char *input = NULL;
    size_t input_size = 0;
    ssize_t bytes_read;

   
    printf("$ ");
    bytes_read = getline(&input, &input_size, stdin);

    if (bytes_read == -1 || feof(stdin)) {
        free(input);
        *active = 0;

        return NULL;
    }

    input[bytes_read - 1] = '\0';

    char **command = NULL;
    char *token = strtok(input, " ");
    int token_count = 0;

    while (token != NULL) {
        command = realloc(command, (token_count + 1) * sizeof(char *));
        if (command == NULL) {
            perror("realloc");
            exit(1);
        }
        command[token_count] = strdup(token);
        token = strtok(NULL, " ");
        token_count++;
    }

    command = realloc(command, (token_count + 1) * sizeof(char *));
    if (command == NULL) {
        perror("realloc");
        exit(1);
    }
    command[token_count] = NULL;

    free(input);
    return command;
}
