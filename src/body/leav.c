/*
** leav.c for  in /home/darkmark/rendu/PSU_2015_42sh/src/body
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Thu Jun  2 22:36:02 2016 Marc Lallias
** Last update Sat Jun  4 16:12:26 2016 
*/

#include "../../inc/minishell2.h"

int	leav_shell(t_int *l_pid, t_put *curr)
{
  while (l_pid)
    {
      if (l_pid->data_int > 0)
	{
	  if (kill(l_pid->data_int, SIGINT) == -1)
	    return (-1);
	}
      l_pid = l_pid->next;
    }
  curr->exit_stat = NEED_EXIT;
  return (-1);
}
