#include "shell.h"

/**
 * list_len - function that determines length of the linked list
 * @h: pointer to the first node of the list
 * Return: the size of the list
 */

size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++
	}
	return (i);
}

/**
 * list_to_strings - function that returns an array of strings of the list str
 * @h: pointer to the first node of the list
 * Return: the array of strings
 */

char **list_to_strings(list_t *h)
{
	list_t *node = h;
	size_t i = list_len(h), j;
	char **str;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next; i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - function that prints all elements of a list_t linked list
 * @h: pointer to the first node of the list
 * Return: size of the list
 */

size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_numer(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - function that returns nodes whereby a string
 * starts with a prefix
 * @h: pointer to the first node on the list
 * @prefix: string to match
 * @c: the next char after the prefx
 * Return: the node matched or NULL
 */

list_t *node_starts_with(list_t *h, char *prefix, char c)
{
	char *p = NULL;

	while (h)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (h);
		h = h->next;
	}
	return (NULL);
}

/**
 * get_node_index - function that gets the index of a node
 * @h: pointer to the first node on the list
 * @node: pointer to the node
 * Return: index or the node or -1 for error
 */

ssize_t get_node_index(list_t *h, list_t *node)
{
	size_t i = 0;

	while (h)
	{
		if (h == node)
			return (i);
		h = h->next;
		i++;
	}
	return (-1);
}
