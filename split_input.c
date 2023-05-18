#include <string.h>
#include <stdlib.h>
#include "shell.h"

/**
 * split_input - Split the input string into tokens
 * @input: The input string
 * Return: An array of tokens
 */
char **split_input(char *input)
{
	int i = 0;
	char *token;
	char **tokens = malloc(sizeof(char *) * 64);

	if (!tokens)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " \t\n\r");

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \t\n\r");
	}
	tokens[i] = NULL;
	return (tokens);
}
