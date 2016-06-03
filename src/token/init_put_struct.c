/*
** init_put_struct.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/token
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu Apr 14 01:35:07 2016 Marc Lallias
** Last update Fri Jun  3 05:07:41 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	close_put_struct(t_put *put)
{
  if (put->r_in != -1)
    close(put->r_in);
  if (put->r_out != -1)
    close(put->r_out);
  if (put->rr_in != -1)
    close(put->rr_in);
  if (put->rr_out != -1)
    close(put->rr_out);
  if (put->p1[0] != -1)
    close(put->p1[0]);
  if (put->p1[1] != -1)
    close(put->p1[1]);
  if (put->p2[0] != -1)
    close(put->p2[0]);
  if (put->p2[1] != -1)
    close(put->p2[1]);
  return (0);
}

int	init_put_struct2(t_put *put)
{
  if (put->rr_in != -1)
    {
      close(put->rr_in);
      put->rr_in = -1;
    }
  if (put->rr_out != -1)
    {
      close(put->rr_out);
      put->rr_out = -1;
    }
  put->env = ENV;
  return (0);
}

int	init_put_struct(t_put *put)
{
  if (put->p1_stat == FULL)
    {
      /* put->p1[0] = -1; */
      put->p1_stat = -1;
    }
  if (put->p2_stat == FULL)
    {
      /* put->p2[0] = -1; */
      put->p2_stat = -1;
    }
  if (put->r_in != -1)
    {
      close(put->r_in);
      put->r_in = -1;
    }
  if (put->r_out != -1)
    {
      close(put->r_out);
      put->r_out = -1;
    }
  return (init_put_struct2(put));
}

int	start_put_struct(t_put *put)
{
  put->argv = NULL;
  put->r_in = -1;
  put->r_out = -1;
  put->rr_in = -1;
  put->rr_out = -1;
  put->p1[0] = -1;
  put->p1[1] = -1;
  put->p2[0] = -1;
  put->p2[1] = -1;
  put->p1_stat = -1;
  put->p2_stat = -1;
  put->ret = 0;
  put->exit_stat = NO_EXIT;
  put->env = ENV;
  return (0);
}
