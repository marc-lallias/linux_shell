/*
** setenv.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/build_in
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Mon Apr  4 14:03:15 2016 Marc Lallias
** Last update Tue May 24 20:18:44 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

t_env	*modifie_env_elem(t_env *elem, char **argv)
{
  char	*new_data;

  new_data = malloc(my_strlen(argv[1]) + my_strlen(argv[2]) + 2);
  if (new_data == NULL)
    return (NULL);
  my_strcopy(new_data, argv[1]);
  my_strcat(new_data, "=");
  if (argv[2] != NULL)
      my_strcat(new_data, argv[2]);
  free(elem->data);
  elem->data = new_data;
  return (elem);
}

t_env	*new_env_elem(t_env *elem, char **argv)
{
  char	*new_data;

  new_data = malloc(my_strlen(argv[1]) + my_strlen(argv[2]) + 2);
  if (new_data == NULL)
    return (NULL);
  my_strcopy(new_data, argv[1]);
  my_strcat(new_data, "=");
  if (argv[2] != NULL)
      my_strcat(new_data, argv[2]);
  return ((make_env_list(elem, new_data)));
}

int	my_setenv(char **argv, t_env **l_env)
{
  t_env	*elem;

  if (argv[1] != NULL)
    {

      elem = cherch_in_env(*l_env, argv[1]);
      if (elem == NULL)
	{
	  if ((*l_env = new_env_elem(*l_env, argv)) == NULL)
	    return (1);
	}
      else
	{
	  if ((modifie_env_elem(elem, argv)) == NULL)
	    return (1);
	}
    }
  else
    aff_env_list(*l_env);
  return (0);
}

