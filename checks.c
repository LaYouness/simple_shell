#include "shell.h"

/**
* check_input - checks data
* @splited_input: arg
*
* BY: HALO & CHROMA
*/
void check_input(char **splited_input)
{

	if (_strncmp(splited_input[0], "exit", 4) == 0)
	{
		if (splited_input[1] != NULL)
		{
			int status = _atoi(splited_input[1]);

			_print_str("\nExiting from shell... Status: ");
			_print_num(status);
			_print_str("\n");
			exit(status);
		}
		else
		{
			_print_str("\nExiting from shell...\n");
			exit(0);
		}
	}
	else if (_strncmp(splited_input[0], "env", 3) == 0)
	{
		env();/*execute the built-in env*/
	}
	else if (_strncmp(splited_input[0], "echo", 4) == 0)
		_echoo(splited_input);
	else
	{
		exe_cmd(splited_input);/*execute cmd*/
	}
}
