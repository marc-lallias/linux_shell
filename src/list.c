/*
** list.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Sun Apr  3 23:52:03 2016 Marc Lallias
** Last update Sun May  1 16:17:57 2016 Marc Lallias
*/

#include "../inc/minishell2.h"

t_env	*rev_env_list(t_env *elem)
{
  t_env	*previus;
  t_env	*keep;

  if (elem == NULL)
    return (NULL);
  previus = NULL;
  keep = elem->next;
  while (keep)
    {
      keep = elem->next;
      elem->next = previus;
      previus = elem;
      if (keep != NULL)
	elem = keep;
    }
  return (elem);
}

t_exe	*rev_exe_list(t_exe *elem)
{
  t_exe	*previus;
  t_exe	*keep;

  if (elem == NULL)
    return (NULL);
  previus = NULL;
  while (keep)
    {
      keep = elem->right;
      elem->right = previus;
      previus = elem;
      if (keep != NULL)
	elem = keep;
    }
  return (elem);
}

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
