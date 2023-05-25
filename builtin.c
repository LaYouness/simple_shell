#include "main.h"

/**
 * check_builtins - Check if the command is a built-in command
 * @command: cmd name
 *
 * BY HALO & CHROMA
 * Return: function or NULL (if not a builtin)
 */

int	 (*check_builtins(char *command))(char *, char **, char ***)
{
	bt list[] = {
		{"env", print_env},
		{"exit", perform_exit},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{"cd", cd},
		{NULL, NULL}
	};
	int i;

	for (i = 0; list[i].cmd; i++)
		if (!_strcmp(command, list[i].cmd))
			return (list[i].f);
	return (NULL);
}
