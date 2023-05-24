#include "shell.h"

/**
* _atoi - convert string to number
* @s: pointer int
*
* BY HALO & CHROMA
*
* Return: int
*/

int _atoi(char *s)
{
	unsigned int cmp = 0, size = 0, o = 0, n = 1, m = 1, i;

	while (*(s + cmp) != '\0')
	{
		if (size > 0 && (*(s + cmp) < '0' || *(s + cmp) > '9'))
			break;

		if (*(s + cmp) == '-')
			n *= -1;

		if ((*(s + cmp) >= '0') && (*(s + cmp) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		cmp++;
	}
	for (i = cmp - size; i < cmp; i++)
	{
		o = o + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (o * n);
}
