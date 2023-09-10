#include "shell.h"

/**
 * free_cmd - a function that free memory
 *
 * @command: the strings of array
 * return: No return
 */

void free_cmd(char **command)
{
        int i = 0;

        if (command == NULL)
                return (NULL);

        while (command[i] != NULL)
        {
                i++;
                free(command[i]);
        }
        free(command);
}
