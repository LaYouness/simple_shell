#include "shell.h"
/**
* env - env built-in
* by youness & sahahr
*/
void env(void)
{
char **envi = environ;

while (*envi)
{
_print_str(*envi);
_print_str("\n");
envi++;
}
}

/**
* main - main_function
* @argc: argument
* @argv: argument
* by: Laila&Mega
*
* Return: always 0 , 1 if it fails
*/
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t n = 0;

	ssize_t chars_read;
	char **splited_input;
	(void) argc;
	(void) argv;

	while (1)
	{
		_prompt();
		chars_read = getline(&line, &n, stdin);
		if (chars_read == -1)
		{
		_print_str("\nExiting from shell...See you later\n");
			break;
		}
		splited_input = split_input(line);
		if (splited_input == NULL)
		{
			continue;
		}

		check_input(splited_input);
		free(line);
		free(splited_input);
	}

	return (0);
}
