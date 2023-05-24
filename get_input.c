#include <stdio.h>
#include "shell.h"

/**
 * get_input - Function that take the input
 * Return: the input
 */

char *get_input()
{
	size_t n = 0;
	ssize_t nline = 0;
	char *line_ptr = NULL;

	nline = getline(&line_ptr, &n, stdin);

	if (nline == -1)
	{
		free(line_ptr);
		return (NULL);
	}

	line_ptr[strcspn(line_ptr, "\n")] = '\0';

	return (line_ptr);
}
