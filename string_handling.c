#include "shell.h"

/**
 * string_length - Calculates the length of a string.
 * @str: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int string_length(char *str)
{
	int length = 0;


	if (!str)
		return (0);


	while (*str++)
		length++;
	return (length);
}

/**
 * string_compare - Performs lexicographic comparison of two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: Negative value if str1 < str2, positive value if str1 > str2,
 *	 or zero if str1 is equal to str2.
 */
int string_compare(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * starts_with - Checks if a string starts with another string.
 * @str: The string to search.
 * @prefix: The substring to find.
 *
 * Return: Address of the next character in str if prefix is found, or NULL.
 */
char *starts_with(const char *str, const char *prefix)
{
	while (*prefix)
		if (*prefix++ != *str++)
			return (NULL);
	return ((char *)str);
}

/**
 * string_concatenate - Concatenates two strings.
 * @dest: The destination buffer.
 * @src: The source buffer.
 *
 * Return: Pointer to the destination buffer.
 */
char *string_concatenate(char *dest, char *src)
{
	char *result = dest;


	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (result);
}
