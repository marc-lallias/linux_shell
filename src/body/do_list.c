/*
** exec_list.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/body
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu Apr 14 00:33:18 2016 Marc Lallias
** Last update Sun May 15 14:54:41 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"


int	do_list(t_exe *to_do, t_env **l_env, t_put *curr)
{
  /* gerer a ce niveau le & */
  while (to_do)
    {
      if ((to_do = choose_token(to_do, l_env, curr)) == NULL)
	{
	  return (1);
	}
      if (to_do)
	to_do = to_do->right;
    }
  if (curr->argv != NULL)
    {
      curr->ret = normal(curr->argv, l_env, curr);
    }

  init_put_struct(curr);/* pr close les pipe dosi faire dns close father */
  return (father_wait(curr));
  return (0);
}

int	do_graph(t_exe *to_do, t_env **l_env, t_put *curr)
{
  while (to_do)
    {
      if ((to_do->data_tab == NULL)
	  || (match_n_match(*(to_do->data_tab), ";") == 1))
	{
	  curr->ret = do_list(to_do->left, l_env, curr);
	  printf("curr->ret:  %d\n", curr->ret);
	}
      init_put_struct(curr);
      to_do = to_do->right;
    }
  return (0);
}
