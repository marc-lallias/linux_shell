/*
** exec_list.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/body
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu Apr 14 00:33:18 2016 Marc Lallias
** Last update Thu Apr 28 16:13:54 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	do_list(t_exe *to_do, t_env **l_env, t_put *curr)
{
  while (to_do)
    {
      to_do = choose_token(to_do, l_env, curr);
      if (to_do)
	to_do = to_do->right;
    }
  if (curr->argv != NULL)
    {
      normal(curr->argv, l_env, curr);
    }
  return (0);
}
