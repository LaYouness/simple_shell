#include "main.h"


/**
 * print_exec - combines the exe, the sep and the int
 * @buff: pointer to buffer
 * @exec: str
 * @n: int
 *
 * BY: HALO & CHROMA
 *
 * Return: int
 */

unsigned int	 print_exec(char *buff, char *exec, int n)
{
	unsigned int	 i;

	for (i = 0; exec[i]; i++)
		buff[i] = exec[i];

	buff[i++] = ':', buff[i++] = ' ';
	buff[i++] = n + '0';
	buff[i++] = ':', buff[i++] = ' ';

	return (i);
}

/**
 * print_command - also combines the cmd, the sep and the int
 * @buff: pointer to buffer
 * @cmd: str
 * @i: int
 *
 * BY: HALO & CHROMA
 * Return: int
 */

unsigned int	 print_command(char *buff, char *cmd, unsigned int i)
{
	unsigned int	 j;

	if (!cmd)
		return (i);
	for (j = 0; cmd[j]; j++)
		buff[i++] = cmd[j];

	buff[i++] = ':', buff[i++] = ' ';

	return (i);
}

/**
 * print_error - combines the error, the sep and the int
 * @buff: pointer to buffer
 * @error: str
 * @i: int
 *
 * BY: HALO & CHROMA
 * Return: int
 */

unsigned int	 print_error(char *buff, char *error, unsigned int i)
{
	unsigned int	 j;

	for (j = 0; error[j]; j++)
		buff[i++] = error[j];

	return (i);
}

/**
 * print_more_text - combines the text, the sep and the int
 * @buff: pointer to buffer
 * @text: text
 * @index: char inserted
 * @i: int
 *
 * BY: HALO & CHROMA
 * Return: int
 */

unsigned int	 print_more_text(char *buff, char *text, char index,
unsigned int	 i)
{
	unsigned int	 j;

	if (!text)
		return (i);

	if (index != 'c')
		buff[i++] = ':', buff[i++] = ' ';
	for (j = 0; text[j]; j++)
		buff[i++] = text[j];

	return (i);
}

/**
 * display_error - Display an error message with additional text
 * @executable: name of the exec
 * @cmd: command
 * @error: error mesg
 * @text: additional text
 *
 * BY: HALO & CHROMA
 * Return: void
 */

void	 display_error(char *executable, char *cmd, char *error, char *text)
{
	char	 *msg;
	static char	 *exec;
	static unsigned int	 n;
	unsigned int	 i;

	if (executable)
	{
		exec = executable;
		return;
	}

	if (!n)
		++n;
	msg = malloc(sizeof(char) * 100);
	if (!msg)
		perror("Can't allocate memory for msg"), exit(1);

	i = print_exec(msg, exec, n), n++;
	i = print_command(msg, cmd, i);
	i = print_error(msg, error, i);
	i = print_more_text(msg, text, error[0], i);

	msg[i++] = '\n', msg[i] = '\0';
	write(STDERR_FILENO, msg, i), free(msg);
}
