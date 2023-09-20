#include "main.h"

/**
 * free_command - Deallocates memory for an array of command tokens.
 *
 * This function is responsible for releasing the memory allocated for
 * an array of command tokens. It takes a pointer to the array as its
 * argument and frees each individual token and the array itself.
 *
 * @command: Pointer to the array of command tokens to be deallocated.
 */
void free_command(char **command)
{
    int i = 0;

    if (command[i] != NULL)
    {
        free(command[i]);
        i++;
    }

    free(command[i]);
    free(command);
}
