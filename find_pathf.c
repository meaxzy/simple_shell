#include "main.h"

/**
* findExecutablePath - Locates the full
* path of an executable command
* by searching through directories listed in the PATH environment variable.
*
* @cmdName: Pointer to the command to be executed; will be updated with
* the full path if found.
*/

void findExecutablePath(char **cmdName)
{
	char *path = getenv("PATH");
	char *pathcp = strdup(path);
	char *token = strtok(pathcp, ":");
	char *try_path = NULL;

	while (token != NULL)
	{
	try_path = malloc(strlen(*cmdName) + strlen(token) + 2);
	sprintf(try_path, "%s/%s", token, *cmdName);

	if (access(try_path, X_OK) == 0)
	{
	free(*cmdName);
	*cmdName = strdup(try_path);
	free(try_path);
	break;
	}
	free(try_path);
	token = strtok(NULL, ":");
	}

	free(pathcp);
}
