#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "shell.h"



/**
 * create_path - funtion that creates the command path
 * @token: the path
 * @command: the command
 * Return: the command path
 */

char *create_path(const char *token, const char *command)
{
	char *command_path = malloc(strlen(token) + strlen(command) + 2);

	sprintf(command_path, "%s/%s", token, command);

	return (command_path);
}


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

	char *path, *token;
	char *command = args[0];

	if (strcmp(command, "exit") == 0)
		exit(0);

	path = getenv("PATH");
	token = strtok(path, ":");


	while (token != NULL)
	{
		char *command_path = create_path(token, command);

		if (access(command_path, X_OK) == 0)
		{
			args[0] = command_path;

			if (execve(command_path, args, NULL) == -1)
			{
			perror("execve");

			free(command_path);
			return (-1);
			}
		}

		free(command_path);

		/*token = strtok(NULL, ":");*/

		return (0);



	}

	printf("%s: command not found\n", command);

	return (-1);
}
