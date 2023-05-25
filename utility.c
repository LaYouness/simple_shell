#include "main.h"

/**
 * free_2D - frees array
 * @arr: array
 * by youness and halo
 */
void free_2D(char **arr)
{
	unsigned int i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = NULL;
}

/**
 * _strlen - calculate str len
 * @s: str
 * Return: len
 */
int _strlen(char *s)
{
	int size, i;

	if (!s)
		return (0);
	i = 0;
	size = 0;
	while (s[i++] != '\0')
		size++;

	return (size);
}

/**
 * _strcmp - compares 2 given  str
 * @s1: string 1
 * @s2: string 2
 * Return: int value
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}

	if (s1[i] != '\0')
		return (s1[i]);
	else if (s2[i] != '\0')
		return (s2[i]);


	return (0);
}

/**
 * _strcpy - copies string
 * @dest: destination
 * @src: source
 * Return: pntr to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];

	return (dest);
}

/**
 * len_2D - get len of 2dimention array
 * @s: array
 * by youness & sahar
 * Return: len
 */
size_t len_2D(char **s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (++i);
}
