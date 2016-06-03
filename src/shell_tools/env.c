/*
** env.c for  in /home/darkmark/rendu/PSU_2015_minishell2/env
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu Mar 31 15:35:34 2016 Marc Lallias
** Last update Fri Jun  3 04:05:43 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

char	**put_in_env(char **build_env, t_env *l_env)
{
  *build_env = NULL;
  while (l_env)
    {
      build_env--;
      *build_env = malloc(my_strlen(l_env->data) + 1);
      if (build_env == NULL)
	{
	  put_err("Malloc 2: build_env\n");
	  return (NULL);
	}
      *build_env = my_strcopy(*build_env, l_env->data);
      l_env = l_env->next;
    }
  return (build_env);
}

char	**build_env(t_env *l_env)
{
  char	**build_env;
  int	list_size;

  build_env = NULL;
  if (l_env == NULL)
    return (NULL);
  list_size = env_list_len(l_env);
  build_env = malloc(sizeof(char *) * (list_size + 1));
  if (build_env == NULL)
    {
      put_err("Malloc 1: build_env\n");
      return (NULL);
    }
  build_env+= (list_size);
  return (put_in_env(build_env, l_env));
}

void    free_env(t_env *elem)
{
  t_env *previus;

  while (elem)
    {
      previus = elem;
      free(elem->data);
      elem->data = NULL;
      elem = elem->next;
      free (previus);
    }
  return ;
}

t_env	*make_env_list(t_env *elem, char *env)
{
  t_env	*new;

  new = malloc(sizeof(t_env));
  if (new == NULL)
    return (NULL);
  if (env != NULL)
    {
      new->data = malloc((my_strlen(env)) + 1);
      if (new->data == NULL)
	return (NULL);
      new->data = my_strcopy(new->data, env);
    }
  new->next = elem;
  return (new);
}

t_env	*env_dup(char **env)
{
  t_env	*elem;

  elem = NULL;
  while (*env)
    {
      elem = make_env_list(elem, *env);
      if (elem == NULL)
	{
	  put_err("Malloc: in env_dup.");
	  return (NULL);
	}
      env++;
    }
  return (elem);
}
