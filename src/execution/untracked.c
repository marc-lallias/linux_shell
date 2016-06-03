/*
** untracked.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/execution
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Sun May  1 18:01:57 2016 Marc Lallias
** Last update Fri Jun  3 18:09:47 2016 
*/

#include "./../inc/minichell2.h"

int	untracked(t_exe	*to_do)
{
  int	child;

  to_do = rev_exe_list(to_do->next);
  child = fork();
  if (child == -1)
    {
      put_err(FORK_FAIL);
    }
  if (pid == 0)
    do_list(to_do);
  else
    return (0);

}
