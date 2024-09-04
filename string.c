#include "shell.h"

/**
 * _strlen - function that checks the length of a string
 * @s: the string
 * Return: the length
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++;
	return (1);
}

/**
 * _strcmp - function that performs lexicographic comparison of two strings
 * @s1:: the first string
 * @s2: the second string
 * Return: zero if strings are equal, negative if s1 < s2
 * or positive if s1 > s2
 */

int _strcmp(char *s1, char *s2)
{
	while (s1 && s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? - 1 : 1)
}

/**
 * starts_with - function that checks if middle starts with haystack
 * @hystack: string search
 * @needle: substring to be found
 * Return: address of char haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: destination
 * @src: source
 * Return: pointer to the destination
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
