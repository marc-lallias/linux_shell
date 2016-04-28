/*
** shell_tools.c for  in /home/darkmark/rendu/PSU_2015_minishell2/env
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu Mar 31 13:58:37 2016 Marc Lallias
** Last update Thu Apr  7 12:53:31 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

char	*pass(char *line, char to_found)
{
  if (line == NULL)
    return (NULL);
  while (*line && *line == to_found)
    {
      if (*line != to_found)
	return (line);
      line++;
    }
  return (line);
}

char	*pass_to(char *line, char to_pass)
{
  if (line == NULL)
    return (NULL);
  while (*line)
    {
      if (*line == to_pass)
	return (line);
      line++;
    }
  return (line);
}

t_env	*cherch_in_env(t_env *env, char *to_found)
{
  while (env)
    {
      if ((match(to_found, env->data)) == 1)
	{
	  return (env);
	}
      env = env->next;
    }
  return (NULL);
}

char	*my_getenv(t_env *l_env, char *to_found)
{
  t_env	*elem;

  if ((elem = cherch_in_env(l_env, to_found)) == NULL)
    return (NULL);
  return ((pass_to(elem->data, '=')) + 1);
  
}
