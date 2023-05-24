#include "shell.h"

/**
* get_env - compare the len of 2 env
* @var: variable
* by youness & sahar
* Return: NULL
*/

char *get_env(const char *var)
{
	char **p = environ;
	size_t len = _strlen(var);

	while (*p != NULL)
	{
	if (_strncmp(var, *p, len) == 0 && (*p)[len] == '=')
	{
	return (&((*p)[len + 1]));
	}
	p++;
	}
	return (NULL);
}
