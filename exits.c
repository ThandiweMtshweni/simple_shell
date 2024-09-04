#include "shell.c"

/**
 **_strncpy - function that copies a string
 * @dest: the destination
 * @src: the source
 * @n: the number of characters to be copied
 * Return: the concatenated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - function that concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the amount of bytes to maximally use
 * Return: the concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;
	char *s = dest;

	while (dest[i] != '\0')
		i++;i
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - function that locates a char in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: pointer to the memory area s
*/

char *_strchr(char *s, char c)
{
	do {
		if (*S == c)
			return (c);
	} while (*s++ != '\0');

	return (NULL);
}
