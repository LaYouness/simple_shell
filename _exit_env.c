#include "main.h"

/**
 * print_env - Print the current environment variables
 * @command: cmd name
 * @args: pointer to array
 * @env: pointer to arg
 *
 * BY: HALO & CHROMA
 * Return: always 1
 */
int print_env(char *command, char **args, char ***env)
{
	int i;

	if (!command || !args || !env)
		perror("NULL arument to print_env()"), exit(1);

	for (i = 0; (*env)[i]; i++)
	{
		write(STDOUT_FILENO, (*env)[i], _strlen((*env)[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

/**
 * my_atoi - Convert a str to an int
 * @n: int
 *
 * BY: HALO & CHROMA
 * Return: num or -1 (if failure)
 */
int my_atoi(char *n)
{
	unsigned int a, num;
	int i;

	num = i = 0;
	while (n[i])
	{
		if (n[i] < '0' || n[i] > '9')
			return (-1);
		i++;
	}
	--i;
	a = 1;
	while (i >= 0)
	{
		num += (n[i] - 48) * a;
		a *= 10;
		i--;
	}
	return (num);
}

/**
 * perform_exit - Exit the shell program
 * @command: cmd name
 * @args: pointer to array
 * @env: pointer to arg
 *
 * BY: HALO & CHROMA
 * Return: EXIT
 */
int perform_exit(char *command, char **args, char ***env)
{
	int status;

	if (!command || !args || !env)
		perror("NULL arument to print_env()"), exit(1);

	if (!args[1])
		status = 0;
	else
	{
		status = my_atoi(args[1]);
		if (status == -1)
		{
			display_error(NULL, command, "Illegal number", args[1]);
			return (1);
		}
	}
	free(command), free(args), free_2D(*env);
	exit(status);
	return (1);
}
