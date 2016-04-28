
/*
** my_arg.c for  in /home/darkmark/rendu/PSU_2015_minishell2/env
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Sat Apr  2 03:23:28 2016 Marc Lallias
** Last update Wed Apr 13 16:55:47 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

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
  char		limit;

  while (*com)
    {
      if (*com == '"' || *com == 39)
	{
	  limit = *com;
	  com = pass_to(com + 1, *com);
	  if (*com == '\0')
	  {
	    put_err("Not matches: ");
	    my_putchar(limit, 2);
	    put_err("\n");
	    return (NULL);
	  }
	}
      if (*com == ' ')
	  return (com);
      if ((check_token(com + 1)) == 1 || ((check_token(com)) == 1))
	return (com + 1);
      com++; 
    }
  return (com);
}

char		**my_argv(char *com)
{
  t_env		*arg;
  char		**argv;
  char		*chevron;
  char		*line;

  arg = NULL;
  while (*com)
    {
      com = pass(com, ' ');
      if (*com != '\0')
      	{
      	  chevron = com;
      	  com = define_arg_content(com);
      	  if (com == NULL)
      	    return (NULL);
      	  line = put_in_arg(chevron, (com - chevron));
      	  if (line == NULL)
      	    return (NULL);
	  if ((arg = make_env_list(arg, NULL)) == NULL)
	    return (NULL);
	  arg->data = line;
	}
    }
  argv = build_env(arg);
  free_env(arg);
  return (argv);
}
