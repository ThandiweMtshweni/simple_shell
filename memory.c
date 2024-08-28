#include "shell.h"

/**
 * bfree - function that frees a pointer and empties the address
 * @p: pointer to the address to be freed
 * Return: 1 to free the pointer or 0 otherwise
 */

int bfree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
