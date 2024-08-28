#include "shell.h"

/**
 * _history - function that diplays history list
 * @info: struct containing arguments
 * Return: Always 0
 */

int _history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - function that sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0
 */

int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;

	ret = delete_node_at_index(&(info->alias), get_node_index
			(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - function that sets the alias to a string
 * @info: parameter struct
 * @str: the string
 * Return: Always 0
 */

int set_alias(info_t *info, char *str)
{
	char *p;

	p = strchar(str, '=');

	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - function that prints the alias
 * @node: the alias node
 * Return: 0 or 1 for error
 */

int print_alias(list_t *node)
{
	char *p = NULL;
	char *a = NULL;

	if (node)
	{
		*p = _strchar(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - function that mimics the alias builtin
 * @info: struct that contains potential arguments
 * Return: 0
 */

int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = strchar(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}
	return (0);
}
