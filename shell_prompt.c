#include "shell.h"

/**
 * main - a function to start a shell command line
 * @argc: argument count
 * @argv: arguments passed by user
 * @env: array of strings of environmental variables
 * Return: 1 if successful, - 1 if failed
 */

int main(int argc, const char **argv)
{
	char *buf = NULL;
	size_t buf_size = 0;
	char **command = NULL;
	size_t get_line;
	int i = 0, active = 1;
	char *token;

	while (active)
	{
		write(1, "$ ", 2);
		get_line = getline(&buf, &buf_size, stdin);
		if (get_line == -1)
		{
			free(buf);
			return (0);
		}
		command = malloc(STRTOK_BUFSIZE * sizeof(char *));
		if (!command)
			exit(EXIT_FAILURE);
		token = strtok(buf, STRTOK_DELIM);

		while (token != NULL)
		{
			command[i] = token;
			token = strtok(NULL, STRTOK_DELIM);
			i++;
		}
	}
	i = 0;
	free(buf);
	return (0);
}
