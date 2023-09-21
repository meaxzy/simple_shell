#include "main.h"

/**
 * tokenize_f - Tokenize a string into simple tokens using space as a delimiter.
 *
 * @line: Pointer to the string to be tokenized.
 *
 * Return: An array of pointers representing the command tokens.
 */
char **tokenize_f(char **line)
{
    char *token; // Temporary token holder
    char *lineCopy = strdup(*line); // Create a copy of the input string
    char **command = NULL; // Array to store tokens
    int numTokens = 0; // Number of tokens
    int i;

    if (line == NULL)
        return NULL;

    // Count the number of tokens in the input string
    token = strtok(*line, " ");
    while (token != NULL)
    {
        numTokens++;
        token = strtok(NULL, " ");
    }

    // Allocate memory for the token array
    command = malloc((numTokens + 1) * sizeof(char *));
    if (command == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Tokenize the input string and store tokens in the array
    token = strtok(lineCopy, " ");
    for (i = 0; i < numTokens; i++)
    {
        command[i] = strdup(token);
        token = strtok(NULL, " ");
    }

    // Null-terminate the array
    command[i] = NULL;

    free(*line);
    free(lineCopy);

    return command;
}
