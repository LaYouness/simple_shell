#include "main.h"


/**
 * update_PWD - Update the value of the PWD environment variable
 * @env: pointer to array
 *
 * BY: HALO & CHROMA
 * Return: 1 (if success), -1 (if failure)
 */

int	 update_PWD(char **env)
{
	char	 cwd[100], *dir;
	size_t	 i;

	i = 100, getcwd(cwd, i);
	for (i = 0; env[i]; i++)
		if (same(env[i], "PWD"))
			break;
	if (!env[i])
		return (-1);
	dir = change_var(cwd, env, i);
	free(env[i]);
	env[i] = dir;
	return (1);
}

/**
 * update_OLDPWD - Update the value of the OLDPWD environment variable
 * @env: pointer to array
 * @val: new value
 *
 * BY: HALO & CHROMA
 * Return: 1 (if success), -1 (if failure)
 */

int	 update_OLDPWD(char **env, char *val)
{
	char *dir;
	unsigned int i;

	for (i = 0; env[i]; i++)
		if (same(env[i], "OLDPWD"))
			break;
	if (!env[i])
		return (-1);
	dir = change_var(val, env, i);
	free(env[i]);
	env[i] = dir;
	return (1);
}
