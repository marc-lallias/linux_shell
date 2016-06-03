/*
** leav.c for  in /home/darkmark/rendu/PSU_2015_42sh/src/body
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu Jun  2 22:36:02 2016 Marc Lallias
** Last update Fri Jun  3 06:01:21 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	leav_shell(t_int *l_pid, t_put *curr)
{
  t_int	*first;

  while (l_pid)
    {
      if (l_pid->data_int > 0)
	kill(l_pid->data_int, SIGINT);
      /* printf("pid-%d\n", l_pid->data_int); */
      l_pid = l_pid->next;
    }
  curr->exit_stat = NEED_EXIT;
  return (-1);
}
