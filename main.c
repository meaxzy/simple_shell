#include "shell.h"

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument array (constant)
 * Return: Always 0; success as 1
 */

int main(int argc, const char **argv)
{
	int active = 1, err_count = 0, exit_status = 0, is_exec;
	char **command;

	while (active)
	{
		command = fetch_cmd(&active);
		if (command != NULL)
		{
			if (strcmp(command[0], "exit") == 0)
			{
				free_cmd(command);
				break;
			}
			if (strcmp(command[0], "env") == 0)
			{
				print_env();
				exit_status = 0;
				free_cmd(command);
				continue;
			}
			is_exec = is_exec(&command[0]);
			if (is_exec == 0)
			{
				err_count++;
				fprintf(stderr, "%s: %d: %s: NOT FOUND\n", argv[0], err_count, command[0]);
				continue;
			}
			else if (is_exec == 1)
			{
				find_Path(&command[0]);
			}
			exec_cmd(command, err_count, exit_status);
		}
	}
	return (exit_status);
}
