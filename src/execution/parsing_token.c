/*
** parsing_token.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/execution
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Sat Apr  9 18:03:46 2016 Marc Lallias
** Last update Mon May  9 14:22:29 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

char	**convert(t_env *start, t_env *end)
{
  t_env	*first;
  char	**tab;
  int	size;

  first = start;
  size = 0;
  while (start != end)
    {
      start = start->next;
      size++;
    }
  if (size == 0)
    return (NULL);
  if ((tab = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  while (first != end)
    {
      *tab = put_in_arg(first->data, my_strlen(first->data));
      first = first->next;
      tab++;
    }
  *tab = NULL;
  tab -= size;
  return (tab);
}

t_exe	*insert_node(char **tab, t_exe *elem)
{
  t_exe	*new;

  if ((new = malloc(sizeof(t_exe))) == NULL)
    return (NULL);
  new->left = NULL;
  new->right = NULL;
  new->data_tab = tab;
  if (elem == NULL)
    return (new);
  new->right = elem;
  return (new);
}

int	check_wrong_line(t_exe *exe, t_env *chevron, t_env *arg)
{
  if (chevron->next == NULL)
    {
      put_err("Unexpected: ");
      put_err(chevron->data);
      put_err("\n");
      return (1);
    }
  if (((check_spliters(chevron->data)) == 1))
    {
      if (arg != chevron->next)
	{
	  put_err("Shouldn't found a: ");
	  put_err(chevron->next->next->data);
	  put_err("\n");
	  return (1);
	}
    }
  else if (arg != chevron->next->next)
    {
      put_err("Shouldn't found a: ");
      put_err(chevron->next->next->data);
      put_err("\n");
      return (1);
    }
  return (0);
}

t_exe	*build_tree(t_exe *exe, t_env *chevron, t_env *arg)
{
  if ((check_build_in(chevron->data) == 1)
      || ((access(chevron->data, X_OK)) == F_OK))
    {
      if ((exe = insert_node(convert(chevron, arg), exe)) == NULL)
	return (NULL);
    }
  else
    {
      if ((check_wrong_line(exe, chevron, arg)) == 1)
	{
	  /* free(exe); */
	  return (NULL);
	}
      if ((exe = insert_node(convert(chevron, chevron->next), exe)) == NULL)
	return (NULL);
      chevron = chevron->next;
      if ((exe->left = insert_node((convert(chevron, arg)), NULL)) == NULL)
	return (NULL);
    }
  return (exe);
}

t_exe	*exec_list(t_env *arg, t_env *l_env)
{
  t_env	*chevron;
  t_exe	*exe;
  int	ret;

  exe = NULL;
  ret = 1;
  chevron = arg;
  if ((check_build_in(arg->data) != 1) && (check_exe(&(arg->data), l_env)) == -1)
    return (NULL);
  while (arg != NULL)
    {
      arg = arg->next;
      if ((arg == NULL) || (((check_signifiant(arg->data)) == 1)
			    || (ret = check_exe(&(arg->data), l_env)) == 1))
	{
	  exe = build_tree(exe, chevron, arg);
	  chevron = arg;
	  if (exe == NULL || ret == -1)
	    {
	      /* free(exe); */
	    return (NULL);
	    }
	}
    }
/* return avant rev list pour voir si & a la fin */
  return (exe);
}
