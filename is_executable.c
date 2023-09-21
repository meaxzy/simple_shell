#include "main.h"

/**
 * is_executable - Determine if a command name is executable or in path or not.
 *
 * @cmdname: pointer to the first token of the command.
 *
 * Return: 0 if not executable,
 * 1 if executable is found in path,
 * 2 if full executable pathname was passed.
 */

int is_executable(char **cmdname)
{
	char *path = getenv("PATH");
	char *pathcp = NULL;
	char *token = NULL;
	char *try_path = NULL;

	if (access(*cmdname, X_OK) == 0 && strstr(*cmdname, "/") != NULL)
		return (2);

	if (path == NULL)
		return (0);

	pathcp = strdup(path);
	token = strtok(pathcp, ":");

	while (token != NULL)
	{
		try_path = malloc(strlen(*cmdname) + strlen(token) + 2);
		sprintf(try_path, "%s/%s", token, *cmdname);

		if (access(try_path, X_OK) == 0)
		{
			free(pathcp);
			free(try_path);
			return (1);
		}
		free(try_path);
		token = strtok(NULL, ":");
	}

	free(pathcp);
	return (0);
}
