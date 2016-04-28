/*
** pipe.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/token
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Tue Apr 12 13:45:29 2016 Marc Lallias
** Last update Thu Apr 14 16:29:50 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

t_exe	*pipe_shell(t_exe *to_do, t_env **l_env, t_put *curr)
{
  if (curr->p1_stat == -1)
    {
      pipe(curr->p1);
      curr->p1_stat = EMPTY;
      if (normal(curr->argv, l_env, curr) == -1)
	return (NULL);
      init_put_struct(curr);
      curr->p1_stat = FULL;
    }
  else
    {
      pipe(curr->p2);
      curr->p2_stat = EMPTY;
	 if (normal(curr->argv, l_env, curr) == -1)
	   return (NULL);
	 init_put_struct(curr);
	 curr->p2_stat = FULL;
    }
  curr->argv = to_do->left->data_tab;
  return (to_do);
}
