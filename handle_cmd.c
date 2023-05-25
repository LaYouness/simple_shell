#include "main.h"


/**
 * same - Compare two strings for equality
 * @s1: 1st str
 * @s2: 2nd str
 *
 * BY HALO & CHROMA
 * Return: 1 (if identical)  0 (if not)
 */

int	 same(char *s1, char *s2)
{
	unsigned int i;

	if (!s1 || !s2)
		return (0);

	for (i = 0; s1[i] && s2[i]; i++)
		if (s1[i] != s2[i])
			return (0);
	if (!s1[i] || !s2[i])
		return (1);

	return (0);
}

/**
 * get_var - Retrieve the value of an environment variable
 * @env: pointer to array
 * @var: str
 *
 * BY HALO & CHROMA
 * Return: HOME (if success) | NULL (if failure)
 */

char	 *get_var(char **env, char *var)
{
	unsigned int i;

	for (i = 0; env[i]; i++)
	{
		if (same(env[i], var))
			return (env[i]);
	}
	return (NULL);
}

/**
 * get_dir - Retrieve the current directory
 * @home: str
 *
 * BY HALO & CHROMA
 * Return: home
 */

char	 *get_dir(char *home)
{
	char	 *dir;
	unsigned int	 i, j;

	for (i = 0; home[i]; i++)
	{}
	dir = malloc(sizeof(char) * (i - 4));
	if (!dir)
		perror("Can't allocate memory for dir"), exit(1);
	j = 0;
	for (i = 0; home[i]; i++)
		if (home[i] == '=')
			break;
	for (++i; home[i]; i++)
		dir[j++] = home[i];
	dir[j] = '\0';

	return (dir);
}

/**
 * to_home - Retrieve the home directory path
 * @env: pointer to array
 * @var: str
 *
 * BY HALO & CHROMA
 * Return: home directory (if success),  NULL (if failure)
 */

char	 *to_home(char **env, char *var)
{
	char *dir, *s;

	if (!env)
		return (NULL);
	s = get_var(env, var);
	if (!s)
		return (NULL);
	dir = get_dir(s);

	return (dir);
}
