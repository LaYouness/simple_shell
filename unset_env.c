#include "main.h"

/**
 * remove_var - removes variable
 * @env: pointer to array
 * @index: index
 *
 * BY: HALO & CHROMA
 * Return: new list or NULL
 */
char **remove_var(char **env, int index)
{
	char **new_env;
	int i, j;

	if (!env || index < 0)
		return (NULL);

	for (i = 0; env[i]; i++)
	{}
	if (i <= index)
	{
		return (NULL);
	}

	new_env = malloc(sizeof(char *) * i);
	if (!new_env)
		perror("Can't allocate memory for new_env"), exit(1);
	for (i = 0; i < index; i++)
	{
		new_env[i] = env[i], env[i] = NULL;
	}

	free(env[i]), env[i] = NULL;
	j = i + 1;
	for (; env[j]; j++)
		new_env[i++] = env[j], env[j] = NULL;

	new_env[i] = NULL;
	return (new_env);
}

/**
 * unset_env - Unset an environment variable from the env
 * @command: cmd name
 * @args: pointer to array
 * @env: pointer to arg
 *
 * BY: HALO & CHROMA
 * Return: always 1
 */
int unset_env(char *command, char **args, char ***env)
{
	int i;
	char **new_env;

	if (!command || !args || !env)
		perror("NULL arument to unset_env()"), exit(1);

	if (!args[0] || !args[1] || args[2])
	{
		display_error(NULL, NULL, "Bad variable name", NULL);
		return (1);
	}

	i = does_exist(args[1], *env);
	if (i < 0)
	{
		display_error(NULL, NULL, "Bad variable name", NULL);
		return (1);
	}
	new_env = remove_var(*env, i);
	free(*env), *env = NULL;
	*env = new_env;

	return (1);

}
