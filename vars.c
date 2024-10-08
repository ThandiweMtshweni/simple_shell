#include "shell.h"

/**
 * is_chain - function that checks if the chaar in buffer is a chain delimeter
 * @info: parameter struct
 * @buf: char buffer
 * @p: addres of current position in buffer
 * Return: 1 for chain delimeter or 0 otherwise
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t i = *p;

	if (buf[i] == '&' && buf[i + 1] == '&')
	{
		buf[i] = 0;
		i++;
		info->cmd_buf_type = CMD_AND
	}
	else if (buf[i] == '|' && buf[i + 1] == '|')
	{
		buf[i] = '0';
		i++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[i] == ';')
	{
		buf[i] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = i;
	return (1);
}

/**
 * check_chain - function checks whether to continue
 * chaining based on the last status
 * @info: parameter struct@buf: char buffer
 * @p: address of the current position
 * @i: starting position in buf
 * @len: length of the buffer
 * Return: void
 */

void check_chain(info *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	*p = j;
}

/**
 * replace_alias - function replaces an aliases in the tockenized string
 * @info: parameter struct
 * Return: 1 to replace or 0 otherwise
 */

int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _struct(node->str, '=');
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - function that replaces vars in the tockenized string
 * @info: parameter stuct
 * Return: 1 to replace and 0 otherwise
 */

int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			 replace_string(&(info->argv[i]),
					 _strdup(convert_number(getpid(), 10, 0)));
			 continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - function that replaces a string
 * @old: the old string
 * @new: the new string
 * Return: 1 to replace and 0 otherwise
 */

int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
