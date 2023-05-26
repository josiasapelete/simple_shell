#include "shell.h"

/**
 * list_len - function that determines length of linked list
 * @ptr: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *ptr)
{
	size_t i = 0;

	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - function that returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *nod = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; nod; nod = nod->next, i++)
	{
		str = malloc(_strlen(nod->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, nod->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - function that prints all elements of a list_t linked list
 * @ptr: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *ptr)
{
	size_t i = 0;

	while (ptr)
	{
		_puts(convert_number(ptr->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(ptr->str ? ptr->str : "(nil)");
		_puts("\n");
		ptr = ptr->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - function that returns
 * node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - function that gets the index of a node
 * @head: pointer to list head
 * @nod: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *nod)
{
	size_t i = 0;

	while (head)
	{
		if (head == nod)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
