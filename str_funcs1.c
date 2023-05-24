#include "shell.h"

/**
* _strcpy - copies source to destimation
* @dest: destination
* @src: source
* by youness & sahar
* Return: string copy
*/
char *_strcpy(char *dest, const char *src)
{
	char *tmp = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';

	return (tmp);
}

/**
* _strncpy - copies source to destination
* @dst: destination arg
* @src: source arg
* @n: num of char to cpy
* by youness & sahar
* Return: string cpy
*/
char *_strncpy(char *dst, const char *src, size_t n)
{
	char *dst_c = dst;

	while (n > 0 && *src != '\0')
	{
		*dst++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*dst++ = '\0';
		n--;
	}
	return (dst_c);
}

/**
* _strlen - calculates the length of string
* @str: str to calculate the len for
* by youness &sahar
* Return: len
*/

size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
* _strncmp - compare two strings 
*@s1: string 1
*@s2: string 2
*@n: num of char to comp
* by youness & sahar
* Return: 0
*/

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}

