/*
1;4002;0c** getenv.h for  in /home/darkmark/perso/my_getenv
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Wed Mar 30 00:32:04 2016 Marc Lallias
** Last update Thu Apr 14 22:44:14 2016 Marc Lallias
*/

#ifndef MINISHELL2_H_
# define MINISHELL2_H_

#include <fcntl.h>
#include <linux/limits.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>

#ifndef EMPTY
# define EMPTY (1)
#endif /* EMPTY */

#ifndef FULL
# define FULL (0)
#endif /* FULL */

typedef struct		s_put
{
  char			**argv;
  int			p1[2];
  int			p1_stat;
  int			p2[2];
  int			p2_stat;
  int			r_in;
  int			r_out;
  int			f_err;
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

/* aff/aff.c */

int		aff_env_list(t_env *env);
void		my_putchar(char c, int outpout);
void		my_put_str(char *str);
void		my_show_tab(char **str);
void		put_err(char *str);

/* body/build_in1.c */

int		build_in1(char **argv, t_env **l_env);

/* body/choose_token.c */

t_exe		*choose_token(t_exe *to_do, t_env **l_env, t_put *curr);

/* body/do_list.c */

int		do_list(t_exe *to_do, t_env **l_env, t_put *curr);

/* build_in/cd.c */

int		move(char *to_go, t_env **l_env);
int		my_cd(char **argv, t_env **l_env);
char		*pwd(t_env *l_env);

/* build_in/setenv.c */

t_env		*modifie_env_elem(t_env *elem, char **argv);
int		my_setenv(char **argv, t_env **l_env);
t_env		*new_env_elem(t_env *elem, char**argv);

/* build_in/unsetenv.c */

void		free_env_elem(t_env *elem);
int		check_all(char *to_del, t_env *elem);
int		my_unsetenv(char **argv, t_env **l_env);

/* build_in/exit.c */

int		my_exit(char **argv, t_env **l_env);

/* execution/apply_redirection.c */

int		apply_redirection(t_put *put);
int		apply_redirection2(t_put *put);
int		close_father(t_put *put);

/* exection/lamba.c */

int		exec(char **argv, t_env **l_env, t_put *put);
int		exec_bin(char **argv, t_env **l_env);
int		normal(char **argv, t_env **l_env, t_put *put);

/* exection/parsing_token.c */

t_exe		*build_list_exec(char **tab, t_exe *elem);
int		check_token(char *str);
t_exe		*exec_list(char **tab);
t_exe		*insert_node(char **tab);

/* list.c */

int		env_list_len(t_env *l_env);

/* manip/manip_string1.c */

char		*my_strcat(char *dest, char *source);
char		*my_strcopy(char *dest, char *source);
int		my_strlen(char *str);

/* manip/manip_tab1.c */

void		my_free_tab(char **tab);
char		**my_realloc_tab(char **tab, int size);

/* match_n_match.c */

int		match(char *to_find, char *find_in);
int		match_complet(char *str1, char *str2);
int		match_n_match(char *to_find, char *find_in);

/* shell/tools/my_argv.c */

char		*define_arg_content(char *com);
char		**my_argv(char *com);
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

int		my_getnbr(char *str);


/* token/init_put_struct.c */

int		close_put_struct(t_put *put);
int		start_put_struct(t_put *put);
int		init_put_struct(t_put *put);


/* token/pipe_shell.c */

t_exe		*pipe_shell(t_exe *to_do, t_env **l_env, t_put *curr);

/* token/semi_colon.c */

t_exe		*semi_colon(t_exe *to_do, t_env **l_env, t_put *curr);

/* token/simple_redirection.c */

t_exe		*left_redir(t_exe *to_do, t_env **l_env, t_put *curr);
t_exe		*right_redir(t_exe *to_do, t_env **l_env, t_put *curr);

/* token/double_redir_right.c */

t_exe		*double_redir_right(t_exe *to_do, t_env **l_env, t_put *curr);

#endif /* MINISHELL2_H_ */

/* UNTRACED */
