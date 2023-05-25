#include "main.h"

/**
 * _execve - exec cmds (execve)
 * @args: cmd + args
 * @env: env vars list
 * @exec: exec name
 *
 * Return: 1 Success 0 Failure
 */

int _execve(char **args, char **env, char *exec)
{
	pid_t my_pid;

	my_pid = fork();
	if (!my_pid)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(exec);
			return (0);
		}
	}
	else if (my_pid < 0)
	{
		perror("Fork fail");
		return (0);
	}
	else
		wait(NULL);
	return (1);
}


/**
 * make_copy - cpy env vars array of strs
 * @env: environment variables
 * by youness & sahar
 * Return: str
 */


char **make_copy(char **env)
{
	char **copy;
	unsigned int i, size;

	if (!env)
		return (NULL);

	copy = malloc(sizeof(char *) * len_2D(env));
	if (!copy)
		perror("Can't allocate memory for copy"), exit(1);
	i = 0;
	while (env[i])
	{
		size = _strlen(env[i]);
		copy[i] = malloc(sizeof(char) * (++size));
		if (!copy[i])
		{
			free_2D(copy);
			perror("Can't allocate memory for copy"), exit(1);
		}
		copy[i] = _strcpy(copy[i], env[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
