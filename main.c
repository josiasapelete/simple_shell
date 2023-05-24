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
	if (isatty(fileno(stdin)))
	{
	char *input = NULL;
	char **args = NULL;

	display_prompt();


	while (1)
	{
	input = get_input();

	if (input == NULL)
		break;

	args = split_input(input);
	if (args == NULL || args[0] == NULL)
	{
		free(input);
		continue;
	}

	execute_command(args);

	free_args(args);
	free(input);

	display_prompt();

	}
	}
	else
	{
		process_input(stdin);
	}

	return (0);
}
