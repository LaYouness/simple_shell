#include "main.h"

#define ARGS_SIZE 1000

/**
 * read_command - reads cmd
 * @env: environ
 * by chroma and halo
 * Return: list of splited args
 */
char *read_command(__attribute__((unused))char **env)
{
	char *buffer;
	size_t i;

	i = 0, buffer = NULL;
	if (getline(&buffer, &i, stdin) == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(buffer), buffer = NULL;
		free_2D(env), env = NULL;
		exit(0);
	}

	remove_comments(buffer);
	if (buffer && (buffer[0] == '\0'))
		buffer[0] = '\n';

	return (buffer);
}

/**
 * read_args - splits cmd to args
 * @buffer: buff
 * @env: env var lt
 * by chromagos and halo
 * Return: array of 'command and arguments' strings
 */
char **read_args(char *buffer, __attribute__((unused))char **env)
{
	char **args;
	char *tok;
	const char *del;
	int n;

	args = malloc(sizeof(char *) * (ARGS_SIZE));
	if (!args)
		perror("Failed to allocate memory for args"), exit(1);

	del = "\t\n ";
	tok = _strtok(buffer, del);
	n = 0;
	while (tok)
	{
		args[n++] = tok;
		tok = _strtok(0, del);
	}
	for (; n < ARGS_SIZE; n++)
		args[n] = NULL;

	return (args);
}

/**
 * execute_command - exec cmd
 * @command: cmd
 * @args: args
 * @env: pntr to env vars list
 * @exec: exec name
 * by youness & sahar
 *
 * Return: one on succ zero on fail
 */
int execute_command(char *command, char **args, char ***env, char *exec)
{
	int (*f)(char *, char **, char ***);
	char *cmd, *old;
	int i;

	if (!command || !args || !env || !exec)
	{
		perror("NULL argument to execute_command()");
		return (0);
	}
	if (args && !args[0])
		return (1);

	f = check_builtins(args[0]);
	if (f)
		return (f(command, args, env));

	old = args[0];
	cmd = full_path(args[0], *env);
	if (!cmd)
		display_error(NULL, args[0], "not found", NULL), i = 1;
	else
	{
		args[0] = cmd;
		i = _execve(args, *env, exec);
		free(cmd);
		args[0] = old;
	}
	return (i);
}
