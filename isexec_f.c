#include "main.h"

/**
* isexec_f - Checks if a command is executable or in the PATH.
*
* @cmdname: Pointer to the first token of the command.
* Return: 0 if not executable,
*         1 if executable is found in the PATH,
*         2 if the full executable pathname was provided.
*/

int isexec_f(char **cmdname)
{
	char *path = getenv("PATH");
	char *pathCopy = NULL;
	char *token = NULL;
	char *tryPath = NULL;

	if (access(*cmdname, X_OK) == 0 && strstr(*cmdname, "/") != NULL)
		return (2);

	if (path == NULL)
		return (0);

	pathCopy = strdup(path);
	token = strtok(pathCopy, ":");

	while (token != NULL)
	{
		tryPath = malloc(strlen(*cmdname) + strlen(token) + 2);
		sprintf(tryPath, "%s/%s", token, *cmdname);

		if (access(tryPath, X_OK) == 0)
		{
			free(pathCopy);
			free(tryPath);
			return (1);
		}
		free(tryPath);
		token = strtok(NULL, ":");
	}

	free(pathCopy);
	return (0);
}
