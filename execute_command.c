#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "shell.h"

/**
 * execute_command - Execute a command
 * @args: Arguments for the command
 *
 * Description: This function executes the specified command by forking
 * a new process and using the execve() system call.
 *
 * Return: On success, returns 0. On failure, returns -1.
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;


	pid = fork();
	if (pid == 0)
	{

		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("forking error");
		exit(EXIT_FAILURE);
	}
	else
	{

		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}


	return (1);
}
