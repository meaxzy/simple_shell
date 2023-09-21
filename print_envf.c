#include "main.h"

/**
 * print_envf - Prints the environment variables.
 */

void print_envf(void)
{
	char **envp = environ;

	for (; envp != NULL && *envp != NULL; envp++)
	{
		printf("%s\n", *envp);
	}
}
