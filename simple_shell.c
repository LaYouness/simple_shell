#include "main.h"

/**
 * main - entry point
 * @ac: arg
 * @av: arg
 * @env: str
 *
 * BY: HALO & CHROMA
 *
 * Return: always 0
 */
int main(__attribute__((unused))int ac, char **av, char **env)
{
	char *cmd, **args, **env_t;
	int i;

	env_t = make_copy(env), i = 1;

	display_error(av[0], NULL, NULL, NULL);

	while (i)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		cmd = read_cmd(env_t);
		args = read_args(cmd, env_t);
		i = execute_cmd(cmd, args, &env_t, av[0]);
		if (cmd)
			free(cmd);
		if (args)
			free(args);
	}
	free_2D(env_t);
	return (0);
}
