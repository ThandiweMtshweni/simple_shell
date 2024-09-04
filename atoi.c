#include "shell.h"

/**
 * inter - checks if shell is in an alteractive mode
 * @info: struct address
 * Return: one for true and 0 otherwise
 */

int inter(info_t *info)
{
	return (isatty(STD_FILENO) && infor->readfd <= 2);
}

/**
 * is_delimeter - function checks if a char is delimeter
 * @c: char to be checked
 * @d: the delimeter string
 * Return: 1 for true and 0 for false
 */

int is_delimeter(char c, char *d)
{
	while (*d)
	{
		if (*d++ == c)
			return (1);
	}
	return (0);
}

/**
 * is_alpha - checks if a char is an alphabet
 * @c: input char
 * Return: 1 for true and 0 otherwise
 */

int is_alpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c >= 'z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - function that converts a string to an int
 * @s: the string to to convert
 * Return: always 0
 */

int _atoi(char *s)
{
	int i, sign, flag, output;
	unsigned int result = 0;

	sign = 1;
	flag = 0;
	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += s[i] - '0';
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -restlt;

	else
		output = result;
	return (output);
}
