#include "shell.h"

/**
 * _memset - Fills a memory area with a constant byte
 * @s: Pointer to the memory area
 * @b: The byte to fill the memory with
 * @n: The number of bytes to fill
 *
 * Return: Pointer to the memory area @s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;


	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * free_strings - Frees an array of strings
 *
 * @str_array: The array of strings
 **/
void free_strings(char **str_array)
{
	char **p = str_array;


	if (!str_array)
		return;
	while (*str_array)
		free(*str_array++);
	free(p);
}

/**
 * reallocate_memory - Reallocates a block of memory
 * @ptr: Pointer to the previous allocated block
 * @old_size: Size of the previous block in bytes
 * @new_size: Size of the new block in bytes
 *
 * Return: Pointer to the reallocated block of memory
 */
void *reallocate_memory(void *ptr, unsigned int old_size,
		unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);


	p = malloc(new_size);
	if (!p)
		return (NULL);


	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
