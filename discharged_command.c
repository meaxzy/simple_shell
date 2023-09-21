#include "main.h"

/**
 * free_command - Frees memory associated with a command array.
 *
 * @command: Pointer to the array of command tokens to be freed.
 * an array of command tokens. It takes a pointer to the array as its
 * argument and frees each individual token and the array itself.
 */

void discharged_command(char **command)
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
