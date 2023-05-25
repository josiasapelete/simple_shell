#include "shell.h"

/**
 * is_cmd - Checks if a file is an executable command
 * @info: Pointer to the info struct
 * @path: Path to the file
 *
 * Return: 1 if the file is an executable command, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;


	(void)info;
	if (!path || stat(path, &st))
		return (0);


	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - Creates a duplicate string from a portion of the original string
 * @pathstr: The original string
 * @start: The starting index
 * @stop: The stopping index
 *
 * Return: Pointer to the new duplicated string
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buffer[1024];
	int i = 0, k = 0;


	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buffer[k++] = pathstr[i];
	buffer[k] = 0;
	return (buffer);
}

/**
 * find_path - Finds the full path of a command in the PATH string
 * @info: Pointer to the info struct
 * @pathstr: The PATH string
 * @cmd: The command to find
 *
 * Return: Pointer to the full path of the command if found, NULL otherwise
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;


	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
