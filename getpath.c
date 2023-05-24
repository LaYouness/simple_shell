#include "shell.h"

/**
* get_path - retrieve the full path
* @cmd: arg
*
* BY: HALO & CHROMA
*
* Return: full path
*/
char *get_path(char *cmd)
{
	char *path, *path_cp, *path_token, *path_file;
	int cmd_len, dir_len;
	struct stat buff;

	path = get_env("PATH");

	if (path)
	{
		path_cp = _strdup(path);
		cmd_len = _strlen(cmd);
		path_token = _strtok(path_cp, ":");

		while (path_token != NULL)
		{
			dir_len = _strlen(path_token);

			path_file = malloc(cmd_len + dir_len + 2);
			_strcpy(path_file, path_token);
			_strcat(path_file, "/");
			_strcat(path_file, cmd);
			_strcat(path_file, "\0");
			if (stat(path_file, &buff) == 0)
			{
				free(path_cp);
				return (path_file);
			}
			else
			{
				free(path_file);
				path_token = _strtok(NULL, ":");
			}
		}
		free(path_cp);
		if (stat(cmd, &buff) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}
