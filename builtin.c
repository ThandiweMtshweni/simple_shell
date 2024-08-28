#include "shell.h"

/**
 * _exit - function that exits the shell
 * @info: struct that contains arguments
 * Return: 0 if info.argv[0] is not "exit"
 */

int _exit(info_t *info)
{
	int exit_chk;

	if (info->arg[1])
	{
		exit_chk = erratoi(info->argv[1]);
		if (exit_chk == -1)
		{
			info->status = 2;
			print_err(info, "Illigal number: ");
			_eputs(info->argv[1]);
			_putchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
}

/**
 * _cd - function to change directory
 * @info: struct containing arguments
 * Return: Always 0
 */

int _cd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg  here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_pits(_getenv(info, "OLDPWD")), _putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't do cd to: ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD+"));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _help - function that changes the current directory
 * @info: struct containing the arguments
 * Return: Always 0
 */

int _help(info_r *info)
{
	char **arg_array = info->argv;

	_puts("help call works, Funcyion not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
