#include "shell.h"

#define MAX_INPUT 1024
#include "shell.h"

/**
 * main - Simple Shell main function
 *
 * Description: This function starts the Simple Shell program by calling
 * the loop function to repeatedly print a prompt, read input, and execute
 * commands until the user exits the program.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char *input = NULL;
	char **args = NULL;
	int status = 0;

	while (1)
	{
	display_prompt();

	input = malloc(sizeof(char) * MAX_INPUT);
	if (input == NULL)
	{
	perror("Malloc error");
	return (EXIT_FAILURE);
	}

	if (fgets(input, MAX_INPUT, stdin) == NULL)
	{
		free(input);
		printf("\n");
		return (EXIT_SUCCESS);
	}

	args = split_input(input);
	if (args == NULL)
	{
		free(input);
		continue;
	}

	status = execute_command(args);

	free_args(args);
	/*free(input);*/
	}

	return (status);
}
