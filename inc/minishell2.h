/*
** getenv.h for  in /home/darkmark/perso/my_getenv
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Wed Mar 30 00:32:04 2016 Marc Lallias
** Last update Fri Jun  3 04:45:24 2016 Marc Lallias
*/

#ifndef MINISHELL2_H_
# define MINISHELL2_H_

#include <fcntl.h>
#include <linux/limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#include "get_next_line.h"

#ifndef EMPTY
# define EMPTY (1)
#endif /* EMPTY */

#ifndef FULL
# define FULL (0)
#endif /* FULL */

#ifndef FOR_READ
# define FOR_READ (0)
#endif /* FOR_READ */

#ifndef FOR_WRITE
# define FOR_WRITE (1)
#endif /* FOR_WRITE */

#ifndef UN_NORMAL
# define UN_NORMAL (1)
#endif /* UN_NORMAL */

#ifndef NORMAL
# define NORMAL (0)
#endif /* FULL */

#ifndef NEED_EXIT
# define NEED_EXIT (1)
#endif /* NEED_EXIT */

#ifndef NO_EXIT
# define NO_EXIT (0)
#endif /* NO_EXIT */

#ifndef ENV
# define ENV (1)
#endif /* NEED_EXIT */

#ifndef NO_ENV
# define NO_ENV (0)
#endif /* NO_ENV */

typedef struct		s_put
{
  char			**argv;
  int			p1[2];
  int			p1_stat;
  int			p2[2];
  int			p2_stat;
  int			r_in;
  int			r_out;
  int			rr_in;
  int			rr_out;
  int			ret;
  int			exit_stat;
  int			env;
}			t_put;

typedef struct		s_env
{
  char			*data;
  struct s_env		*next;
}			t_env;

typedef	struct		s_exe
{
  char			**data_tab;
  struct s_exe		*left;
  struct s_exe		*right;
}			t_exe;

typedef struct		s_int
{
  int			data_int;
  struct s_int		*next;
}			t_int;

/* aff/aff.c */

int		aff_env_list(const t_env *env);
void		my_putchar(const char c, int outpout);
void		my_put_str(char *str);
void		my_show_tab(char **str);
void		put_err(char *str);

/* body/build_in1.c */

int		build_in(char **argv, t_env **l_env);
int		build_in_child(char **argv, t_env **l_env);
int		build_in_father(char **argv, t_env **l_env);
int		check_build_in(char *str);

/* body/choose_token.c */

t_exe		*choose_token(t_exe *to_do, t_env **l_env, t_put *curr);

/* body/do_list.c */

int		do_list(t_exe *to_do, t_env **l_env, t_put *curr);
int		do_graph(t_exe *to_do, t_env **l_env, t_put *curr);

/* body/leav.c */

int		leav_shell(t_int *l_pid, t_put *curr);

/* build_in/cd.c */

int		move(char *to_go, t_env **l_env);
int		my_cd(char **argv, t_env **l_env);
char		*pwd(t_env *l_env);

/* build_in/echo.c */

int		my_echo(char **argv, t_env **l_env);

/* build_in/setenv.c */

int		my_setenv(char **argv, t_env **l_env);

/* build_in/unsetenv.c */

void		free_env_elem(t_env *elem);
int		check_all(char *to_del, t_env *elem);
int		my_unsetenv(char **argv, t_env **l_env);

/* build_in/exit.c */

int		my_exit(char **argv, int *err);/* faire int *ret */

/* execution/apply_redirection.c */

int		apply_redirection(t_put *put);
int		apply_redirection2(t_put *put);
int		close_father(t_put *put);

/* execution/check_exe.c */

int		check_exe(char **str, t_env *l_env);

/* execution/father_wait.c */

int		father_wait(t_int *l_pid, t_put *curr);

/* exection/lamba.c */

int		exec(char **argv, t_env **l_env, char **env, t_put *put);
int		exec_bin(char **argv, char **env);
char		*next_path(char *buff, char *try, char *arg1);
int		normal(char **argv, t_env **l_env, t_put *put);

/* execution/make_graph.c */

t_exe		*make_graph(t_exe *to_do);

/* exection/parsing_token.c */

int		check_spliters(char *str);
t_exe		*exec_list(t_env *com, t_env *env);

/* free.c */

void		free_t_int(t_int *elem);
void		free_t_exe(t_exe *elem);

/* list.c */

t_env		*rev_env_list(t_env *elem);
int		env_list_len(const t_env *l_env);
t_int		*put_in_int(t_int *elem);
t_exe		*put_in_exe(t_exe *elem);
  
/* manip/manip_string1.c */

char		*my_strcat(char *dest, const char *source);
char		*my_strcopy(char *dest, const char *source);
int		my_strlen(char *str);
char		*my_str_n_copy(char *dest, const char *src, int size);


/* manip/manip_tab1.c */

int		my_tab_len(char **tab);
void		my_free_tab(char **tab);
char		**my_realloc_tab(char **tab, int size);

/* match_n_match.c */

int		match(char *to_find, char *find_in);
int		match_complet(char *str1, char *str2);
int		match_n_match(char *to_find, char *find_in);

/* shell/tools/my_argv.c */

char		*define_arg_content(char *com);
t_env		*my_argv(char *com);
char            *pass_arg(char *str);
char		*put_in_arg(char *str, int size);

/* shell_tool/env.c */

char		**build_env(t_env *l_env);
void		free_env(t_env *l_env);
t_env		*env_dup(char **env);
t_env		*make_env_list(t_env *l_env, char *env);

/* shell_tools/shell_tools.c */

int		change_env(t_env **l_env, char *name, char *data);
t_env		*cherch_in_env(t_env *env, char *to_found);
char		*my_getenv(t_env *l_env, char *to_found);
char		*pass(char *line, char pass);
char		*pass_to(char *line, char to_pass);

/* tools/my_getnbr.c */

int		my_getnbr(char *str, int *err);

/* token/check.c */

int             check_token(char *str);
int		check_signifiant(char *str);
int		check_redir(char *str);

/* token/double_redir.c */

t_exe		*double_redir_left(t_exe *to_do, t_env **l_env, t_put *curr);
t_exe		*double_redir_right(t_exe *to_do, t_env **l_env, t_put *curr);

/* token/init_put_struct.c */

int		close_put_struct(t_put *put);
int		start_put_struct(t_put *put);
int		init_put_struct(t_put *put);

/* token/pipe_shell.c */
int		pipe_shell(t_exe *to_do, t_env **l_env, t_put *curr);

/* token/semi_colon.c */

t_exe		*semi_colon(t_exe *to_do, t_env **l_env, t_put *curr);

/* token/simple_redirection.c */

t_exe		*left_redir(t_exe *to_do, t_env **l_env, t_put *curr);
t_exe		*right_redir(t_exe *to_do, t_env **l_env, t_put *curr);
#endif /* MINISHELL2_H_ */

/* checker si right cd */

/* checker si arv > ARG_MAX dans lambda ou parsing_token */

/* Parseur "PEG" (generateur du paseur). */

/* scac > | fait seg */
