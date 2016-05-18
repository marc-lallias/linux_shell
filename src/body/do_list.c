/*
** exec_list.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/body
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu Apr 14 00:33:18 2016 Marc Lallias
** Last update Wed May 18 17:18:21 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"


int		do_list(t_exe *to_do, t_env **l_env, t_put *curr)
{
  t_int		*l_pid;
  /* gerer a ce niveau le & */
  l_pid = NULL;
  while (to_do)
    {
      if ((match_n_match(*(to_do->data_tab), "|")) == 1)
	{
	  l_pid = put_in_int(l_pid);
	  l_pid->data_int = pipe_shell(to_do, l_env, curr);
	}
      else if ((to_do = choose_token(to_do, l_env, curr)) == NULL)
	return (1);
      if (to_do)
	to_do = to_do->right;
    }
  if (curr->argv && (check_build_in(*(curr->argv)) == 1) && (l_pid == NULL))
      return (build_in(curr->argv, l_env));
  else if (curr->argv != NULL)
    {
      l_pid = put_in_int(l_pid);
      l_pid->data_int = normal(curr->argv, l_env, curr);
    }
  /* while (l_pid) */
  /*   { */
  /*     printf("++%d\n", l_pid->data_int); */
  /*     l_pid = l_pid->next; */
  /*   } */
  init_put_struct(curr);/* pr close pipe devrait faire dns close father */
  return (father_wait(l_pid));
}

int	do_graph(t_exe *to_do, t_env **l_env, t_put *curr)
{
  /* printf("curr->ret:  %d\n", curr->ret); */
  while (to_do)
    {
      if ((to_do->data_tab == NULL)
	  || (match_n_match(*(to_do->data_tab), ";") == 1))
	{
	  curr->ret = do_list(to_do->left, l_env, curr);
	  /* free to_do->left */
	}
      else if ((match_n_match(*(to_do->data_tab), "&&") == 1)
	       && (curr->ret == 0))
	{
	  curr->ret = do_list(to_do->left, l_env, curr);
	  /* free to_do->left */
	}
      else if ((match_n_match(*(to_do->data_tab), "||") == 1)
	       && (curr->ret != 0))
	{
	  curr->ret = do_list(to_do->left, l_env, curr);
	  /* free to_do->left */
	}
      init_put_struct(curr);
      to_do = to_do->right;
    }
  return (0);
}
