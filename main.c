#include "main.h"


/**
 * main - the initialization of the main function, command entry..
 *
 * @ac: number of arguments.
 * @av: array of arguments.
 *
 * Return: Exit_point (0) for success.
 */
int main(int ac, char **av)
{
	int entry_point = 1, errors = 0, exit_point = 0, isexec;
	char **command = NULL;
	ac = ac;

	while (entry_point)
	{
		command = incoming_command(&entry_point);
		if (command != NULL)
		{
			if (strcmp(command[0], "exit") == 0)
			{
				discharged_command(command);
				break;
			}
			if (strcmp(command[0], "env") == 0)
			{
				print_envf();
				exit_point = 0;
				discharged_command(command);
				continue;
			}
			if (strcmp(command[0], "setenv") == 0)
			{
				if (command[1] != NULL && command[2] != NULL)
				{
					if (setenv_command(command[1], command[2]) != 0)
					{
						fprintf(stderr, "%s: %d: Error setting environment variable\n", av[0], errors);
						exit_point = 1;
					}
				}
				else
				{
					fprintf(stderr, "%s: %d: Usage: setenv VARIABLE VALUE\n", av[0], errors);
					exit_point = 1;
				}
				discharged_command(command);
				continue;
			}
			if (strcmp(command[0], "unsetenv") == 0)
			{
				if (command[1] != NULL)
				{
					if (unsetenv_command(command[1]) != 0)
					{
						fprintf(stderr, "%s: %d: Error unsetting environment variable\n", av[0], errors);
						exit_point = 1;
					}
				}
				else
				{
					fprintf(stderr, "%s: %d: Usage: unsetenv VARIABLE\n", av[0], errors);
					exit_point = 1;
				}
				discharged_command(command);
				continue;
			}
			isexec = isexec_f(&command[0]);
			if (isexec == 0)
			{
				(errors)++;
				fprintf(stderr, "%s: %d: %s: not found\n", av[0], errors, command[0]);
				exit_point = 127;
				discharged_command(command);
				continue;
			}
			else if (isexec == 1)
				find_pathf(&command[0]);
			exec_command(command, &errors, &exit_point);
		}
	}
	return (exit_point);
}
