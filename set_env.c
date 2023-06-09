#include "main.h"


/**
 * add_var - Add a new environment variable to the env
 * @env: pointer to array
 * @name: var name
 * @value: var value
 *
 * BY HALO & CHROMA
 * Return: updated env
 */

char	 **add_var(char **env, char *name, char *value)
{
	char	 *var, **new_env;
	unsigned int i;

	new_env = alloc_space(env);
	if (!new_env)
		perror("Can't allocate space for new_env"), exit(1);

	var = new_var(name, value);
	if (!var)
		perror("Can't allocate space for new_var"), exit(1);

	for (i = 0; new_env[i]; i++)
	{}
	new_env[i] = var;
	return (new_env);
}

/**
 * change_var - change var value
 * @value: updated value
 * @env: pointer to array
 * @index: index
 *
 * BY HALO & CHROMA
 * Return: Pointer to the modified env variable
 */

char	 *change_var(char *value, char **env, int index)
{
	char	 *name, *mod_var;
	unsigned int i, j;

	if (!value || !env || index < 0)
		return (NULL);
	name = get_name(env[index]);
	if (!name)
		perror("error while changing varibale"), exit(1);
	mod_var = malloc(sizeof(char) * _strlen(name) + _strlen(value) + 2);
	for (i = 0; name[i]; i++)
		mod_var[i] = name[i];
	mod_var[i++] = '=';
	for (j = 0; value[j]; j++)
		mod_var[i++] = value[j];
	mod_var[i] = '\0';

	free(name);
	return (mod_var);
}

/**
 * does_exist - checks if an environment variable exists or not
 * @var: variable name
 * @env: environment variables list
 *
 * Return: index in env (exists) | -1 (does not exist)
 */

int	 does_exist(char *var, char **env)
{
	char	 *name;
	int	 i;

	for (i = 0; env[i]; i++)
	{
		name = get_name(env[i]);
		if (!name)
			perror("error while looking for variable in env"), exit(1);
		if (!_strcmp(name, var))
		{
			free(name);
			return (i);
		}
		free(name);
	}
	return (-1);
}

/**
 * set_env - Set or modify an environment variable
 * @command: cmd name
 * @args: arg
 * @env: pointer to arg
 *
 * BY HALO & CHROMA
 * Return: always 1
 */

int	 set_env(char *command, char **args, char ***env)
{
	int	 i;
	char	 **new_env;
	char	 *new_val;

	if (!command || !args || !env)
		perror("NULL arument to set_env()"), exit(1);

	if (!args[0] || !args[1] || !args[2] || args[3])
	{
		display_error(NULL, NULL, "Bad variable name", NULL);
		return (1);
	}

	i = does_exist(args[1], *env);
	if (i >= 0)
	{
		new_val = change_var(args[2], *env, i);
		free((*env)[i]);
		(*env)[i] = new_val;
	}
	else
	{
		new_env = add_var(*env, args[1], args[2]);
		free(*env), *env = NULL;
		*env = new_env;
	}

	return (1);
}
