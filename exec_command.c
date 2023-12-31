#include "main.h"

/**
 * exec_command - Executes a command and handles process status.
 *
 * This function takes a command as input, forks a child process to execute
 * the command, and then waits for the child process to complete. It also
 * handles error conditions and updates the number of errors and the shell's
 * exit code accordingly.
 *
 * @command: Pointer to a NULL-terminated array of command tokens.
 * @errs: Pointer to the number of errors that occurred.
 * @exit_code: Pointer to the shell's exit code.
 */

void exec_command(char **command, int *errs, int *exit_code)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		return;
	}
	if (pid == 0)
	{

		if (execve(command[0], command, environ) == -1)
		{
			(*errs)++;
			perror("Execve failed");
		}
		discharged_command(command);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			*exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			fprintf(stderr, "Child process killed by signal: %d\n", WTERMSIG(status));
			*exit_code = WTERMSIG(status);
		}
		discharged_command(command);
	}
}
