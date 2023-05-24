#include "shell.h"

/**
* _prompt - Displays a prompt for the user
*
*/
void _prompt(void)
{
	_print_str("$ ");
	fflush(stdout);
}

/**
* exe_cmd - executes a cmd with the specified arg
* @argv: arg
*
* BY: HALO & CHROMA
*
* Return: if success 0, if error -1
*/
int exe_cmd(char **argv)
{
	pid_t pid;
	int stat;
	char *cmd;

	cmd = get_path(argv[0]);
	if (cmd == NULL)
	{
		_print_str("./Shell: Command not found\n");
		return (-1);
	}
	pid = fork();

	if (pid < 0)
	{
		perror("fork error");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(cmd, argv, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &stat, 0) == -1)
		{
			perror("waitpid fail");
			return (-1);
		}
	}
	return (0);
}
