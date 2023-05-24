#include "shell.h"

/**
* _putchar - prints char to std output
* @c: char
* by youness & sahar
* Return: printed char
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
* _print_str - prints a string into the std output
* @str: string to print
* by youness & sahahr
* Return: num of chars printed by the func
*/

int _print_str(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
* _print_num - prints a num int
* @n: int variable
* BY YOUNESS & SAHAR
*/
void _print_num(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n / 10 != 0)
		_print_num(n / 10);

	_putchar('0' + (n % 10));
}
/**
* _strcat - concatenates 2 strings
* @dst: buffer of destination
* @src: source buffer
* by youness & sahar
* Return: pntr to destination
*/

char *_strcat(char *dst, char *src)
{
	char *r = dst;

	while (*dst)
		dst++;
	while (*src)
		*dst++ = *src++;
	*dst = *src;
	return (r);
}

/**
* _strdup - duplicates a str
* @s: str to dup
* by youness & sahar
* Return: duplicated str
*/

char *_strdup(const char *s)
{
	char *d;
	size_t i, len;

	if (s == NULL)
		return (NULL);
	len = _strlen(s);
	d = malloc((len + 1) * sizeof(char));

	if (d == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		d[i] = s[i];

	d[len] = '\0';

	return (d);
}
