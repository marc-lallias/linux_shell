/*
** main.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Mon Apr  4 00:15:15 2016 Marc Lallias
** Last update Sat Jun  4 23:06:24 2016 
*/

#include "../inc/minishell2.h"

void	handler(int signal)
{
  (void)signal;
}

static void	put_prompt(void)
{
  char		buff[PATH_MAX + 1];

  if (getcwd(buff, PATH_MAX) == NULL)
    my_put_str(PROMPT);
  else
    {
      my_put_str(buff);
      my_put_str(": ");
    }
}

static int	prep_execution(char *line, t_env **l_env, int *exit)
{
  t_env		*arg;
  t_exe		*to_do;
  t_put		curr;

  if ((arg = my_argv(line)) == NULL)
    return (1);
  if ((to_do = exec_list(arg, *l_env)) == NULL)
    {
      free_env(arg);
      return (1);
    }
  if ((to_do = make_graph(to_do)) != NULL)
    {
      start_put_struct(&curr);
      do_graph(to_do, l_env, &curr);
      close_put_struct(&curr);
    }
  free_env(arg);
  free_t_exe(to_do);
  if (curr.exit_stat == NEED_EXIT)
    *exit = NEED_EXIT;
  return (curr.ret);
}

static int	prompt(t_env **l_env)
{
  char		*line;
  int		ret;
  int		exit;

  ret = 0;
  exit = 0;
  put_prompt();
  while ((exit != NEED_EXIT) && ((line = get_next_line(0)) != NULL))
    {
      ret = prep_execution(line, l_env, &exit);
      free(line);
      if (exit == NEED_EXIT)
	my_put_str(PUT_EXIT);
      else
	put_prompt();
    }
  free_env(*l_env);
  my_putchar('\n', 1);
  return (ret);
}

int	main(int ac, char **av, char **env)
{
  t_env	*l_env;

  (void)ac;
  (void)av;
  signal(SIGINT, handler);
  l_env = env_dup(env);
  if (l_env == NULL)
    {
      put_err(ERR_NO_ENV);
    }
  return ((prompt(&l_env)));
}
