/*
** my_arg.c for  in /home/darkmark/rendu/PSU_2015_minishell2/env
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Sat Apr  2 03:23:28 2016 Marc Lallias
** Last update Thu May  5 19:13:07 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

char		*pass_arg(char *str)
{
  while (*str && ((*str == ' ') || (*str == '\t')))
    {
      str++;
    }
  return (str);
}

char		*put_in_arg(char *str, int size)
{
  char		*first;
  char		*new;
  char		limit;

  limit = 0;
  new = malloc(size + 1);
  if (new == NULL)
    return (NULL);
  first = new;
  while (size > 0)
    {
      if ((*str == '"' || *str == 39) && limit == 0)
	limit = *str;
      if (*str != limit || limit == 0)
	{
	  *new = *str;
	  new++;
	}
      str++;
      size--;
    }
  *new = '\0';
  return (first);
}

char		*define_arg_content(char *com)
{
  int		ret;

  while (*com)
    {
      if (*com == '"' || *com == 39)
	{
	  com = pass_to(com + 1, *com);
	  if (*com == '\0')
	  {
	    put_err("Not matches\n");
	    return (NULL);
	  }
	}
      if (*com == ' ')
	  return (com);
      if ((ret = check_token(com)) != 0)
	  return (com + ret);
      if ((check_token(com + 1)) != 0)
	return (com + 1);

      com++; 
    }
  return (com);
}

t_env		*pars_commande(t_env *arg, char **com)
{
  char		*chevron;
  char		*line;
  
  *com = pass_arg(*com);/* y avait un check '\0' */
  chevron = *com;
  if ((*com = define_arg_content(*com)) == NULL)
    {
      free_env(arg);
      return (NULL);
    }
  if ((line = malloc((*com - chevron) + 1)) == NULL)
    return (NULL);
  /* check globing si c est est un retourn son arg (a l'envers) */
  line = my_str_n_copy(line, chevron, *com - chevron);
  if ((arg = make_env_list(arg, NULL)) == NULL)
    return (NULL);
  arg->data = line;
  return (arg);
}

t_env		*my_argv(char *com)
{
  t_env		*arg;
  char		**argv;
  char		*line;

  arg = NULL;
  while (*com)
    {
      if ((arg = pars_commande(arg, &com)) == NULL)
	{
	  return (NULL);
	}
    }
  arg = rev_env_list(arg);
  return (arg);
}
