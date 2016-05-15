/*
** apply_redirection.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/execution
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu Apr 14 01:24:58 2016 Marc Lallias
** Last update Sun May 15 15:51:59 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	close_father(t_put *put)
{
  if (put->p1_stat == EMPTY)
    {
      close((put->p1)[FOR_READ]);
      (put->p1)[FOR_READ] = -1;
    }
  if (put->p1_stat == FULL)
    {
      close((put->p1)[FOR_WRITE]);
      (put->p1)[FOR_WRITE] = -1;
    }
  if (put->p2_stat == EMPTY)
    {
      close((put->p2)[FOR_READ]);
      (put->p2)[FOR_READ] = -1;
    }
  if (put->p2_stat == FULL)
    {
      close((put->p2)[FOR_WRITE]);
      (put->p2)[FOR_WRITE] = -1;
    }
  return (0);
}

int	apply_redirection(t_put *put)
{
  if (put->p1_stat == EMPTY)
    {
      dup2((put->p1)[FOR_READ], 0);
      close((put->p1)[FOR_WRITE]);
    }
  if (put->p1_stat == FULL)
    {
      dup2((put->p1)[FOR_WRITE], 1);
      close((put->p1)[FOR_READ]);
    }
  if (put->p2_stat == EMPTY)
    {
      dup2((put->p2)[FOR_READ], 0);
      close((put->p2)[FOR_WRITE]);
    }
  if (put->p2_stat == FULL)
    {
      dup2((put->p2)[FOR_WRITE], 1);
      close((put->p2)[FOR_READ]);
    }
  return (apply_redirection2(put));
}

int	apply_redirection2(t_put *put)
{
  if (put->r_in != -1)
    dup2(put->r_in, 0);
  if (put->r_out != -1)
    dup2(put->r_out, 1);
  if (put->rr_in != -1)
    dup2(put->rr_in, 0);
  if (put->rr_out != -1)
    dup2(put->rr_out, 1);
  return (0);
}
