#include "shell.h"

/**
 * split_string - Splits a string into words based on delimiters.
 * @str: The input string.
 * @delimiters: The delimiters used for splitting.
 *
 * Return: A pointer to an array of strings, or NULL on failure.
 */
char **split_string(char *str, char *delimiters)
{
	int i, j, k, m, num_words = 0;
	char **split;


	if (str == NULL || str[0] == '\0')
		return (NULL);
	if (!delimiters)
		delimiters = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delimiter(str[i], delimiters) &&
				(is_delimiter(str[i + 1], delimiters) || !str[i + 1]))
			num_words++;


	if (num_words == 0)
		return (NULL);
	split = malloc((1 + num_words) * sizeof(char *));
	if (!split)
		return (NULL);
	for (i = 0, j = 0; j < num_words; j++)
	{
		while (is_delimiter(str[i], delimiters))
			i++;
		k = 0;
		while (!is_delimiter(str[i + k], delimiters) && str[i + k])
			k++;
		split[j] = malloc((k + 1) * sizeof(char));
		if (!split[j])
		{
			for (k = 0; k < j; k++)
				free(split[k]);
			free(split);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			split[j][m] = str[i++];
		split[j][m] = '\0';
	}
	split[j] = NULL;
	return (split);
}

/**
 * split_string2 - Splits a string into words based on a delimiter.
 * @str: The input string.
 * @delimiter: The delimiter used for splitting.
 *
 * Return: A pointer to an array of strings, or NULL on failure.
 */
char **split_string2(char *str, char delimiter)
{
	int i, j, k, m, num_words = 0;
	char **split;


	if (str == NULL || str[0] == '\0')
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != delimiter && str[i + 1] == delimiter) ||
				(str[i] != delimiter && !str[i + 1]) || str[i + 1] == delimiter)
			num_words++;
	if (num_words == 0)
		return (NULL);
	split = malloc((1 + num_words) * sizeof(char *));
	if (!split)
		return (NULL);
	for (i = 0, j = 0; j < num_words; j++)
	{
		while (str[i] == delimiter && str[i] != delimiter)
			i++;
		k = 0;
		while (str[i + k] != delimiter && str[i + k] && str[i + k] != delimiter)
			k++;
		split[j] = malloc((k + 1) * sizeof(char));
		if (!split[j])
		{
			for (k = 0; k < j; k++)
				free(split[k]);
			free(split);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			split[j][m] = str[i++];
		split[j][m] = '\0';
	}
	split[j] = NULL;
	return (split);
}
