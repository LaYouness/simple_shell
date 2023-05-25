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
	char *command, **args, **env_t;
	int i;

	env_t = make_copy(env), i = 1;

	display_error(av[0], NULL, NULL, NULL);

	while (i)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		command = read_command(env_t);
		args = read_args(command, env_t);
		i = execute_command(command, args, &env_t, av[0]);
		if (command)
			free(command);
		if (args)
			free(args);
	}
	free_2D(env_t);
	return (0);
}
