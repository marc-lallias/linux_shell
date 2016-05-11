/*
** exec_list.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/body
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu Apr 14 00:33:18 2016 Marc Lallias
** Last update Wed May 11 00:52:12 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	do_list(t_exe *to_do, t_env **l_env, t_put *curr)
{
  while (to_do)
    {
      if ((to_do = choose_token(to_do, l_env, curr)) == NULL)
	{
	  return (1);
	}
      if (to_do)
	to_do = to_do->right;
    }
  if (curr->argv != NULL)
    {
       curr->ret = normal(curr->argv, l_env, curr);
    }
  return (0);
}
