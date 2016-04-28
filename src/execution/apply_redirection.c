/*
** apply_redirection.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/execution
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu Apr 14 01:24:58 2016 Marc Lallias
** Last update Thu Apr 14 23:57:06 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	close_father(t_put *put)
{
  if (put->p1_stat == FULL)
    {
      close((put->p1)[1]);
      put->p1[1] = -1;
    }
  if (put->p2_stat == FULL)
    {
      close(put->p2[1]);
      put->p2[1] = -1;
    }
  return (0);
}

int	apply_redirection(t_put *put)
{
  if (put->p1_stat == EMPTY)
    {
      dup2(put->p1[EMPTY], 1);
      close(put->p1[0]);
    }
  if (put->p1_stat == FULL)
    {
      dup2(put->p1[FULL], 0);
      close(put->p1[1]);
    }
  if (put->p2_stat == EMPTY)
    {
      dup2(put->p2[EMPTY], 1);
      close(put->p2[0]);
    }
  if (put->p2_stat == FULL)
    {
      dup2(put->p2[FULL], 0);
      close(put->p2[1]);
    }
  return (apply_redirection2(put));
}

int	apply_redirection2(t_put *put)
{
  if (put->r_in != -1)
    dup2(put->r_in, 0);
  if (put->r_out != -1)
    {
      dup2(put->r_out, 1);
    }
  return (0);
}
