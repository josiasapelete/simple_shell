#include <stdio.h>
#include "shell.h"

/**
 * process_input - Function that takes the input from the process
 * @input: the input
 */
void process_input(FILE *input)
{
	char *line = NULL;
	char **args;
	size_t n = 0;
	ssize_t nline;

	while ((nline = getline(&line, &n, input)) != -1)
	{
		line[strcspn(line, "\n")] = '\0';

		args = split_input(line);

		execute_command(args);
		free_args(args);

		free(line);
		line = NULL;

		n = 0;
	}

	free(line);
}
