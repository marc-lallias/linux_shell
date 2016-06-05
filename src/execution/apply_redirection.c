/*
** apply_redirection.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/execution
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Thu Apr 14 01:24:58 2016 Marc Lallias
** Last update Sun Jun  5 18:27:06 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	close_father(t_put *put)
{
  if (put->p1_stat == EMPTY)
    {
      if (close((put->p1)[FOR_READ]) == -1)
	return (-1);
      (put->p1)[FOR_READ] = -1;
    }
  if (put->p1_stat == FULL)
    {
      if (close((put->p1)[FOR_WRITE]) == -1)
	return (-1);
      (put->p1)[FOR_WRITE] = -1;
    }
  if (put->p2_stat == EMPTY)
    {
      if (close((put->p2)[FOR_READ]) == -1)
	return (-1);
      (put->p2)[FOR_READ] = -1;
    }
  if (put->p2_stat == FULL)
    {
      if (close((put->p2)[FOR_WRITE]) == -1)
	return (-1);
      (put->p2)[FOR_WRITE] = -1;
    }
  return (0);
}

int	apply_redirection(t_put *put)
{
  if (put->p1_stat == EMPTY)
    {
      if (dup2((put->p1)[FOR_READ], 0) == -1)
	put_err(DUP_FAIL);
      if (close((put->p1)[FOR_WRITE]) == -1)
	put_err(DUP_FAIL);
    }
  if (put->p1_stat == FULL)
    {
      if (dup2((put->p1)[FOR_WRITE], 1) == -1)
	put_err(DUP_FAIL);
    }
  if (put->p2_stat == EMPTY)
    {
      if (dup2((put->p2)[FOR_READ], 0) == -1)
	put_err(DUP_FAIL);
      if (close((put->p2)[FOR_WRITE]) == -1)
	put_err(CLOSE_FAIL);
    }
  if (put->p2_stat == FULL)
    {
      if (dup2((put->p2)[FOR_WRITE], 1) == -1)
	put_err(DUP_FAIL);
    }
  return (apply_redirection2(put));
}

int	apply_redirection2(t_put *put)
{
  if (put->r_in != -1)
    if (dup2(put->r_in, FOR_READ) == -1)
      put_err(DUP_FAIL);
  if (put->r_out != -1)
    if (dup2(put->r_out, FOR_WRITE) == -1)
      put_err(DUP_FAIL);
  if (put->rr_in != -1)
    if (dup2(put->rr_in, FOR_READ) == -1)
      put_err(DUP_FAIL);
  if (put->rr_out != -1)
    if (dup2(put->rr_out, FOR_WRITE) == -1)
      put_err(DUP_FAIL);
  return (0);
}
