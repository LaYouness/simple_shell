#include "main.h"

/**
 * is_del - determine delim
 * @c: char
 * @del: bytes
 * by youness & halo
 * Return: 1 or 0
 */
int is_del(char c, const char *del)
{
	int i;

	for (i = 0; del[i]; i++)
		if (c == del[i])
			return (1);
	return (0);
}

/**
 * _strtok - tokenize str
 * @s: str
 * @del: del
 * by youness & sahar
 * Return: pntr to next token
 */
char *_strtok(char *s, const char *del)
{
	static char *t;
	char *tok;

	if (s)
		t = s;
	while (*t && is_del(*t, del))
		*t = '\0', t++;
	tok = t;
	if (!(*tok))
		return (NULL);
	while (*t && !is_del(*t, del))
		t++;

	if (*t)
		*t = '\0', t++;
	return (tok);
}

/**
 * remove_comments - rm comms
 * @buffer: buffer
 * by youness & sahar
 * Return: buffer cleared
 */
char *remove_comments(char *buffer)
{
	unsigned int i;

	for (i = 0; buffer[i]; i++)
		if (buffer[i] == '#')
			break;
	for (; buffer[i]; i++)
		buffer[i] = '\0';
	return (buffer);
}
