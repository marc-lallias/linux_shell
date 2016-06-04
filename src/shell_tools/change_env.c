/*
** change_env.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/shell_tools
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Thu Apr  7 14:46:05 2016 Marc Lallias
** Last update Sun Jun  5 00:02:28 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

t_env	*modifie_change_elem(t_env *elem, char *name, char *data)
{
  char	*new_data;

  new_data = malloc(my_strlen(name) + my_strlen(data) + 2);
  if (new_data == NULL)
    return (NULL);
  my_strcopy(new_data, name);
  my_strcat(new_data, "=");
  if (data != NULL)
    my_strcat(new_data, data);
  free(elem->data);
  elem->data = new_data;
  return (elem);
}

t_env	*new_change_elem(t_env *elem, char *name, char *data)
{
  t_env	*new;
  char  *new_data;

  new_data = malloc(my_strlen(name) + my_strlen(data) + 2);
  if (new_data == NULL)
    return (NULL);
  my_strcopy(new_data, name);
  my_strcat(new_data, "=");
  if (data != NULL)
    my_strcat(new_data, data);
  if ((new = make_env_list(elem, NULL)) == NULL)
    return (NULL);
  new->data = new_data;
  return (new);
}

int	change_env(t_env **l_env, char *name, char *data)
{
  t_env	*elem;

  if (l_env == NULL)
    return (0);
  if (name != NULL)
    {
      elem = cherch_in_env(*l_env, name);
      if (elem == NULL)
	{
	  if ((*l_env = new_change_elem(*l_env, name, data)) == NULL)
	    return (-1);
	}
      else
	{
	  if ((modifie_change_elem(elem, name, data)) == NULL)
	    return (-1);
	}
    }
  else
    put_err(NOT_ENOUGH_ARG);
  return (0);
}
