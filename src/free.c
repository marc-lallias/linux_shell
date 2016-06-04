/*
** free.c for  in /home/darkmark/rendu/PSU_2015_42sh/src
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Wed Jun  1 00:46:11 2016 Marc Lallias
** Last update Sat Jun  4 22:56:50 2016 
*/

#include "../inc/minishell2.h"

void	free_t_int(t_int *elem)
{
  t_int	*previous;

  while (elem)
    {
      previous = elem;
      elem = elem->next;
      free(previous);
    }
  return ;
}

void	free_t_exe(t_exe *elem)
{
  t_exe	*previous;

  while (elem)
    {
      previous = elem;
      elem = elem->right;
      if (previous->left != NULL)
	free_t_exe(previous->left);
      my_free_tab(previous->data_tab);
      free(previous);
    }
  return ;
}
