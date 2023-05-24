#include "shell.h"

/**
 * free_args - Free allocated memory for arguments
 * @args: Array of strings containing the arguments
 *
 * This function takes an array of strings as a parameter and frees
 * the allocated memory for each element of the array as well as
 * the array itself.
 *
 * @args: The array of arguments to be freed
 */
void free_args(char **args)
{
	if (args == NULL)
		return;

	free(args);
}
