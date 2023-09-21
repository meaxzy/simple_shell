#include "main.h"

/**
* print_environ - prints the environment variables
*
*/

void print_environ(void)
{
	char **envp = environ;

	for (; envp != NULL && *envp != NULL; envp++)
		printf("%s\n", *envp);
}
