#include "main.h"

/**
 * setenv_command - Functions for managing environment variables
 *
 * @variable: pointer to a char array of the name of the environ variable
 * @value: pointer to a char array the value to set for the environ variable
 *
 * Return: 0 success, 1 failure
 */

int setenv_command(char *variable, char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		fprintf(stderr, "set_environment_variable: Can't set environ variable\n");
		return (1);
	}
	return (0);
}

/**
 * unsetenv_command - Removes an environment variable
 *
 * @variable: pointer to a char array of the name of the environ variable
 *
 * Return: 0 success, 1 failure
 */

int unsetenv_command(char *variable)
{
	if (unsetenv(variable) != 0)
	{
		fprintf(stderr, "unset_environment_variable: Can't unset env variable\n");
		return (1);
	}
	return (0);
}
