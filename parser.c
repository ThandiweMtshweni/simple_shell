#include "shell.h"

/**
 * is_cmd  function that determines whether a file is executable command
 * @info: the info struct
 * @path: file path
 * Return: 1 for true and 0 otherwise
 */

int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);
	if (st.st_mode & S_IFREG)
		return (1);
	return (0);
}

/**
 * dup_chars - function that duplicates chars
 * @pstr: the path string
 * @start: the starting index
 * @stop: the stopping index
 * Return: pointer to the new buffer
 */

char *dup_chars(char *pstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, j = 0;

	for (j = 0; i = start; i < strop; i++)
		if (pstr[i] != ':')
			buf[j++] = pstr[i];
	buf[j] = 0;
	return (buf);
}

/**
 * find_path - function that finds the cmd in the PATH string
 * @info:  the info struct
 * @pstr: the PATH string
 * @cmd: the cmd to be found
 * Return: the full PATH of the cmd that was found
 */

char *find_path(info_t *info, char *pstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pstr[i] || pstr[i] == ':')
		{
			path = dup_chars(pstr, curr_pos, i);
			if (path)
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			else
				_strcat(path, cmd);
			if (is_cmd(info, path))
				return (path);
			if (!pstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
