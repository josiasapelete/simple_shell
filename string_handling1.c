#include "shell.h"

/**
 * copy_string - Copies a string from source to destination.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: Pointer to the destination string.
 */
char *copy_string(char *dest, char *src)
{
	int i = 0;


	if (dest == src || src == NULL)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * duplicate_string - Creates a duplicate of a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string.
 */
char *duplicate_string(const char *str)
{
	int length = 0;
	char *dup;


	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	dup = malloc(sizeof(char) * (length + 1));
	if (!dup)
		return (NULL);
	for (length++; length--;)
		dup[length] = *--str;
	return (dup);
}

/**
 * print_string - Prints a string to stdout.
 * @str: The string to be printed.
 *
 * Return: None.
 */
void print_string(char *str)
{
	int i = 0;


	if (!str)
		return;
	while (str[i] != '\0')
	{
		write_character(str[i]);
		i++;
	}
}

/**
 * write_character - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: On success, 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int write_character(char c)
{
	static int i;
	static char buf[WRITE_BUFFER_SIZE];


	if (c == FLUSH_BUFFER || i >= WRITE_BUFFER_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != FLUSH_BUFFER)
		buf[i++] = c;
	return (1);
}
