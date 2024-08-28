#include "shell.h"

/**
 * _erratoi - function that converts a string to an int
 * @s: the string to convert
 * Return: 0 if no numbers in the string, convert otherwise
 */

int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
	{
		s++;
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - function that prints aerror messages
 * @info: the parameter
 * @estr: string containing error type
 * Return: 0 if theres numbers in string,
 * convert the number otherwise
 */

int print_error(info_t *info, char *estr)
{

	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function that prints a decimal
 * @input: user input
 * @fd: the field descriptor to write to
 * Return: the number of chars to be printed
 */

int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count;

	count = 0;

	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			current++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;
	return (count);
}

/**
 * convert_number - function converter, clone of itoa
 * @num: the number to convert
 * @base: base of the number
 * @flags: argument flags
 * Return: string
 */

char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	unsigned long n = num;
	char *ptr;
	char sign = 0;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function that replaces the first instance of # with \0
 * @buf: address of the string to be modified
 * Return: void
 */

void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
