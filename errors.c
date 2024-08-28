#include "shell.c"

/**
 * _eputs - function that prints input string
 * @str: the input sting
 * Return: void
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - function that writes a character to stderr
 * @c: the character to be written
 * Return: 1 for success, -1 for error
 */

int _eputchar(char c)
{
	static ont i;
	static char bug[WRITE_BUF_SIZE];

	if (c == BUFF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - function that writes char c to a fiven file descriptor
 * @c: the character to be written
 * @fd: the file descriptor to write to
 * Return: 1 for success and -1 for error
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUFF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - function that prints an input string
 * @str: string to be printed
 * @fd: the file descriptor to write to
 * Return: total number of chars
 */

int _putsfd(char *str, int fd)
{
	innt i = 0;

	if (!str)
		return (0);
	while (*str)
		i += _putfd(*str++, fd);
	return (i);
}

