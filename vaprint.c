#include "shell.h"

/**
* _snprint - print data
* @str: pointer
* @size: arg
* @format: arg
*
* BY: HALO & CHROMA
* Return: number
*/
int _snprint(char *str, size_t size, const char *format, ...)
{
	int sum = 0;
	size_t n = 0;
	va_list list;

	va_start(list, format);
	while (format[n] != '\0' && n < size - 1)
	{
		if (sum < (int)size - 1)
		{
			str[sum] = format[n];
			sum++;
		}
		n++;
	}
	if (sum < (int)size)
		str[sum] = '\0';

	va_end(list);
	return (sum);
}
