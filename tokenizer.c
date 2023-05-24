#include "shell.h"

/**
* split_input - split agiven string to tokens
* @line: string
* BY TO YOUNESS & SAHAR
*
* Return: araay of tokens
*/
char **split_input(char *line)
{
	const char *delimiters = " \n";
	const char *tokens;
	int number_tokens = 0, i;
	char *line_copy;
	char **argv;
	line_copy = _strdup(line);
	tokens = _strtok(line_copy, delimiters);
	if (tokens == NULL)
	{
		return (NULL);
	}
	while (tokens != NULL)
	{
		number_tokens++;
		tokens = _strtok(NULL, delimiters);
	}
	number_tokens++;
	argv = malloc(sizeof(char *) * number_tokens);
	tokens = _strtok(line, delimiters);
	for (i = 0; tokens != NULL; i++)
	{
		argv[i] = _strdup(tokens);
		tokens = _strtok(NULL, delimiters);
	}
	argv[i] = NULL;
	free(line_copy);
	return (argv);
}
