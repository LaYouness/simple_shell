#ifndef H
#define H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

/** by youness & sahar*/

/**
 * struct builtin - built ins to exec
 * @cmd: cmd and builtin
 * @f: func pntr to exec bultin
 */

typedef struct builtin
{
	char *cmd;
	int (*f)(char *, char **, char ***);
} bt;

int	 (*check_builtins(char *))(char *, char **, char ***);

char	 *read_command(char **);
char	 **read_args(char *, char **);
int	 execute_command(char *, char **, char ***, char *);


char	 *get_PATH(char **);
char	 **make_copy(char **);
char	 *get_command(char *, char *);
char	 *is_path(char *, char *);
void	 fill_buff(char *, char *);
ssize_t _getline(char **, size_t *, int);
int	 _execve(char **, char **, char *);
char	 *full_path(char *, char **);

int	 print_env(char *, char **, char ***);
int	 perform_exit(char *, char **, char ***);
int	 set_env(char *, char **, char ***);
int	 unset_env(char *, char **, char ***);
int	 cd(char *, char **, char ***);


char	 *get_name(char *);
int	 does_exist(char *, char **);
char	 *change_var(char *, char **, int);
char **add_var(char **, char *, char *);
char	 **alloc_space(char **);
char	 *new_var(char *, char *);
char	 **remove_var(char **, int);
char	 *get_var(char **, char *);
char	 *get_dir(char *);
char	 *to_home(char **, char *);
int	 update_PWD(char **);
int	 update_OLDPWD(char **, char *);


void	 free_2D(char **);
int	 _strcmp(char *, char *);
int	 _strlen(char *);
char	 *_strcpy(char *, char *);
int	 is_del(char, const char *);
char	 *_strtok(char *, const char *);
char	 *remove_comments(char *);
int	 my_atoi(char *);
size_t	 len_2D(char **);
int	 same(char *, char *);
char	 *_copy(char *);


void	 display_error(char *, char *, char *, char *);
unsigned int	 print_exec(char *, char *, int);
unsigned int	 print_command(char *, char *, unsigned int);
unsigned int	 print_error(char *, char *, unsigned int);
unsigned int	 print_more_text(char *, char *, char, unsigned int);

#endif
