/*
** pipe.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/token
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Tue Apr 12 13:45:29 2016 Marc Lallias
** Last update Tue May 31 16:36:41 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	pipe_shell(t_exe *to_do, t_env **l_env, t_put *curr)
{
  int	ret;

  if (curr->p1_stat == -1)
    {
      if (pipe(curr->p1) == -1)
	{
	  /* perror(); */
	  put_err("pipe failed.\n");
	  return (-1);
	}
      curr->p1_stat = EMPTY;
      ret = normal(curr->argv, l_env, curr);
      init_put_struct(curr);
      curr->p1_stat = FULL;
    }
  else
    {
      if (pipe(curr->p2) == -1)
	{
	  /* perror(); */
	  put_err("pipe failed.\n");
	  return (-1);
	}
      curr->p2_stat = EMPTY;
      ret = normal(curr->argv, l_env, curr);
      init_put_struct(curr);
      curr->p2_stat = FULL;
    }
  return (ret);
}
