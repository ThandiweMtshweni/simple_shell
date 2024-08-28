#include "shell.h"

/**
 * hsh - function that contains shell loop
 * @info: the parameter
 * @av: argument vector
 * Return: 0 success or 1 otherwise
 */

int hsh(info_t *info, char **av)
{
	ssize r = 0;
	int builtin_ret = 0;

	while (r != -1&& builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interctive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - function that finds a built in command
 * @info: the paramenter
 * Return: -1 if not found, 0 for success
 * 1 for fail and -2 to exit
 */

int find_builtin(info_t *info)
{
	int i, built_in_ret = -1;

	builtin_table builtintb1[] = {
		{"exit", _exit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintb1[i].type; i++)
		if (_strcmp(info->argv[0], builtintb[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintb[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - function that finds a command in PATH
 * @info: the parameter
 * Return: void
 */

void *find_cmd(info_t *info)
{
	char *path = NULL;
	int i, j;

	info->path =  info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0; j = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], "\t\n"))
				j++;
	if (!j)
		return;
	path = find_path(info, __getenv(info, "PATH+"), info->argv[0]);
	if (!path)
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
	else
	{
		info->path = path;
		fork_cmd(info);
	}	
}

/**
 * fork_cmd = function that forks an exec thread to rum cmd
 * @info: the parameter
 * Return: void
 */

void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
