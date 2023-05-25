#include "shell.h"

/**
 * list_len - Calculates the length of a linked list
 * @h: Pointer to the first node
 *
 * Return: The size of the list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;


	while (h)
	{
		h = h->next;
		count++;
	}


	return (count);
}

/**
 * list_to_strings - Converts the list elements to an array of strings
 * @head: Pointer to the first node
 *
 * Return: The array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t list_size = list_len(head);
	char **strings_array;
	char *string;


	if (!head || !list_size)
		return (NULL);


	strings_array = malloc(sizeof(char *) * (list_size + 1));
	if (!strings_array)
		return (NULL);


	for (size_t i = 0; node; node = node->next, i++)
	{
		string = malloc(_strlen(node->str) + 1);
		if (!string)
		{
			for (size_t j = 0; j < i; j++)
				free(strings_array[j]);
			free(strings_array);
			return (NULL);
		}


		string = _strcpy(string, node->str);
		strings_array[i] = string;
	}


	strings_array[list_size] = NULL;
	return (strings_array);
}

/**
 * print_list - Prints all elements of a linked list
 * @h: Pointer to the first node
 *
 * Return: The size of the list
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;


	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		count++;
	}


	return (count);
}

/**
 * node_starts_with - Searches for a node with a string
 * that starts with a given prefix
 * @node: Pointer to the head of the list
 * @prefix: The prefix string to match
 * @c: The next character after the prefix to match
 *
 * Return: The matched node, or NULL if not found
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *matched_prefix = NULL;


	while (node)
	{
		matched_prefix = starts_with(node->str, prefix);
		if (matched_prefix && ((c == -1) || (*matched_prefix == c)))
			return (node);
		node = node->next;
	}


	return (NULL);
}

/**
 * get_node_index - Gets the index of a node in the linked list
 * @head: Pointer to the head of the list
 * @node: Pointer to the node
 *
 * Return: The index of the node, or -1 if not found
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;

	while (head)
	{
		if (head == node)
			return (index);
		head = head->next;
		index++;
	}


	return (-1);
}
