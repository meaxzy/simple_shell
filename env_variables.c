#include "main.h"

/**
 * env_variables.c - Functions for managing environment variables
 *
 * This file contains implementations of functions for initializing, modifying,
 * and removing environment variables used in the simple shell program.
 *
 * initializeEnvironmentVariable() - Initializes a new environment variable or
 * modifies an existing one.
 * Command syntax: setenv VARIABLE VALUE
 *
 * removeEnvironmentVariable() - Removes an environment variable.
 * Command syntax: unsetenv VARIABLE
 *
 * These functions utilize standard library functions (setenv and unsetenv)
 * to manipulate environment variables and provide error handling by
 * printing error messages to stderr in case of failure.
 */

int setenv_command(char *variable, char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
	fprintf(stderr, "set_environment_variable: Unable to set environment variable\n");
		return (1);
	}
	return (0);
}

int unsetenv_command(char *variable)
{
	if (unsetenv(variable) != 0)
	{
	fprintf(stderr, "unset_environment_variable: Unable to unset environment variable\n");
		return (1);
	}
	return (0);
}
