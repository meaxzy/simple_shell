#include "main.h"

/**
 * print_envf - Prints the environment variables.
 */
void print_envf(void)
{
    char **envp = environ; // Get a pointer to the environment variables

    for (; envp != NULL && *envp != NULL; envp++)
    {
        printf("%s\n", *envp); // Print each environment variable
    }
}
