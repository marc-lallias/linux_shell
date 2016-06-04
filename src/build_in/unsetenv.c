/*
** unsetenv.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/build_in
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Mon Apr  4 16:58:19 2016 Marc Lallias
** Last update Sat Jun  4 16:39:36 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

void		free_env_elem(t_env *elem)
{
  free(elem->data);
  free(elem);
  return ;
}

int		check_all(char *to_del, t_env *elem)
{
  t_env		*keep;

  if (elem->next)
    {
      while (elem->next->next)
	{
	  if ((match(to_del, elem->next->data)) == 1)
	    {
	      keep = elem->next;
	      elem->next = elem->next->next;
	      free_env_elem(keep);
	    }
	  elem = elem->next;
	}
    }
  if ((match(to_del, elem->next->data)) == 1)
    {
      free_env_elem(elem->next);
      elem->next = NULL;
    }
  return (0);
}

int		my_unsetenv(char **argv, t_env **l_env)
{
  t_env		*elem;

  if (argv[1] == NULL)
    {
      put_err(NEEDED_ARG);
      return (1);
    }
  if (*l_env == NULL)
    {
      put_err(NEEDED_ENV);
      return (1);
    }
  elem = *l_env;
  if ((match(argv[1], elem->data)) == 1)
    {
      *l_env = (*l_env)->next;
      free_env_elem(elem);
      return (1);
    }
  return ((check_all(argv[1], *l_env)));
}
