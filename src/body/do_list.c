/*
** exec_list.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/body
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Thu Apr 14 00:33:18 2016 Marc Lallias
** Last update Sun Jun  5 18:18:53 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	do_list(t_exe *to_do, t_env **l_env, t_put *curr)
{
  t_int	*l_pid;

  l_pid = NULL;
  while (to_do)
    {
      if ((match_n_match(*(to_do->data_tab), "|")) == 1 )
	{
	  l_pid = put_in_int(l_pid);
	  if ((l_pid->data_int = pipe_shell(to_do, l_env, curr)) == -1)
	    return (leav_shell(l_pid, curr));
	}
      else if ((to_do = choose_token(to_do, l_env, curr)) == NULL)
	return (1);
      if (to_do)
	to_do = to_do->right;
    }
  l_pid = put_in_int(l_pid);
  if ((l_pid->data_int = normal(curr->argv, l_env, curr)) == -1)
    return (leav_shell(l_pid, curr));
  if (init_put_struct(curr) == -1)
    return (leav_shell(l_pid, curr));
  return (father_wait(l_pid, curr));
}

int	last_token(t_exe *to_do, t_env **l_env, t_put *curr)
{
  char	**loc_argv;
  int	ret;

  if ((match_n_match(*(curr->argv), "exit") == 1))
    {
      loc_argv = curr->argv;
      if (do_list(to_do, l_env, curr) == -1)
	return (-1);
      curr->ret = my_exit(loc_argv, &ret);
      if (ret != 1)
	curr->exit_stat = NEED_EXIT;
      return (curr->ret);
    }
  else if ((curr->argv != NULL) && (check_build_in(*(curr->argv)) == 1))
    {
      loc_argv = curr->argv;
      if (do_list(to_do, l_env, curr) == 1)
	return (-1);
      curr->ret = build_in(loc_argv, l_env);
      return (curr->ret);
    }
  return (do_list(to_do, l_env, curr));
}

int	check_last_token(t_exe *to_do, t_env **l_env, t_put *curr)
{
  if (curr->argv != NULL)
    {
      if (match_n_match(*(curr->argv), "echo") == 1)
	return (do_list(to_do, l_env, curr));
      if ((match_n_match(*(curr->argv), "setenv") == 1)
	  && (curr->argv[1] == NULL))
	return (do_list(to_do, l_env, curr));
      if (match_n_match(*(curr->argv), "env") == 1)
	return (do_list(to_do, l_env, curr));
      return (last_token(to_do, l_env, curr));
    }
  return (do_list(to_do, l_env, curr));
}

int	preli_do_list(t_exe *to_do, t_env **l_env, t_put *curr)
{
  while (to_do)
    {
      if (match_n_match(*(to_do->data_tab), "|") == 1)
	{
	  return (check_last_token(to_do, l_env, curr));
	}
      if ((to_do = choose_token(to_do, l_env, curr)) == NULL)
	return (1);
      if (to_do)
	to_do = to_do->right;
    }
  return (check_last_token(to_do, l_env, curr));
}

int	do_graph(t_exe *to_do, t_env **l_env, t_put *curr)
{
  while (to_do)
    {
      if ((curr->ret = preli_do_list(to_do->left, l_env, curr)) == -1)
  	return (1);
      to_do = to_do->right;
      if (to_do && match_n_match(*(to_do->data_tab), "&&") == 1)
  	{
  	  if (curr->ret != 0)
  	    {
  	      while (to_do && (match_n_match(*(to_do->data_tab), ";") != 1))
		to_do = to_do->right;
  	    }
  	}
      else if (to_do && match_n_match(*(to_do->data_tab), "||") == 1)
  	{
  	  if (curr->ret != 1)
	    {
  	      while (to_do && (match_n_match(*(to_do->data_tab), ";") != 1))
		to_do = to_do->right;
	    }
  	}
    }
  return (curr->ret);
}
