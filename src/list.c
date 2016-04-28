/*
** list.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Sun Apr  3 23:52:03 2016 Marc Lallias
** Last update Mon Apr  4 00:27:17 2016 Marc Lallias
*/

#include "../inc/minishell2.h"

int	env_list_len(t_env *env)
{
  int	size;

  size = 0;
  while (env)
    {
      size++;
      env = env->next;
    }
  return (size);
}
