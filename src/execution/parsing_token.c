
/*
** parsing_token.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/execution
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Sat Apr  9 18:03:46 2016 Marc Lallias
** Last update Fri May 27 18:45:47 2016 Marc Lallias
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

t_exe	*insert(char **tab, t_exe *elem)
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

int	check_validity_token(t_env *chevron)
{
  if (chevron->next == NULL)/* la message erreur unxpected > */
    {
      put_err(chevron->data);
      put_err(" :Unexected.\n");
      return (1);
    }
  if (check_spliters(chevron->next->data) == 1)/*lamessage erreur unxpected >*/
    {
      put_err(chevron->data);
      put_err(" :Unexected.\n");
      return (1);
    }
  if (check_redir(chevron->next->data) == 1)/* la message erreur unxpected > */
    {
      put_err(chevron->data);
      put_err(" :Unexected.\n");
      return (1);
    }
  return (0);
}
t_exe	*build_tree(t_exe *exe, t_env *chevron, t_env *arg)
{
  if ((check_spliters(chevron->data)) == 1)
    {
      if (check_validity_token(chevron) == 1)
	return (NULL);
      if ((exe = insert(convert(chevron, chevron->next), exe)) == NULL)
  	return (NULL);
      chevron = chevron->next;
    }
  else if ((check_redir(chevron->data)) == 1)
    {
      if (check_validity_token(chevron) == 1)
	return (NULL);
      if ((exe = insert(convert(chevron, chevron->next), exe)) == NULL)
  	return (NULL);
      chevron = chevron->next;
      if ((exe = insert(convert(chevron, chevron->next), exe)) == NULL)
  	return (NULL);
      chevron = chevron->next;
    }
  if (arg != chevron)
    {
      if ((exe = insert(convert(chevron, arg), exe)) == NULL)
	return (NULL);
    }
  return (exe);
}

t_exe	*exec_list(t_env *arg, t_env *l_env)/* ajouter first */
{
  t_env	*chevron;
  t_exe	*exe;
  int	ret;

  exe = NULL;
  ret = 1;
  chevron = arg;
  /* if (((check_build_in(arg->data)) != 1) */
  /*     && ((check_exe(&(arg->data), l_env)) == -1)) */
  /*   return (NULL); */
  while (arg != NULL)
    {
      arg = arg->next;
      if ((arg == NULL) || ((check_redir(arg->data)) == 1)
	  || ((check_spliters(arg->data)) == 1))
	{
	  exe = build_tree(exe, chevron, arg);
	  if (exe == NULL)
	    {
	      /* free(first); */
	    return (NULL);
	    }
	  chevron = arg;
	}
    }
/* return avant rev list pour voir si & a la fin */
  return (exe);
}
