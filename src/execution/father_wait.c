/*
** father_wait.c for  in /home/darkmark/rendu/PSU_2015_42sh/src/execution
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Wed May 18 13:58:00 2016 Marc Lallias
** Last update Sun Jun  5 18:29:22 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	father_wait(t_int *l_pid, t_put *curr)
{
  t_int	*first;
  int	status;
  int	ret;

  (void)curr;
  status = 0;
  ret = 1;
  first = l_pid;
  while (l_pid)
    {
      waitpid(l_pid->data_int, &status, WUNTRACED);
      if (WIFSIGNALED(status))
  	{
  	  if (WCOREDUMP(status))
  	    {
  	      put_err(SEG_ERR);
  	      ret = 1;
  	    }
  	}
      ret = WEXITSTATUS(status);
      l_pid = l_pid->next;
    }
  free_t_int(first);
  return (ret);
}
