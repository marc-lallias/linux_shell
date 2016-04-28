/*
** parsing_token.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/execution
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Sat Apr  9 18:03:46 2016 Marc Lallias
** Last update Thu Apr 14 23:07:35 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	check_token(char *str)
{
  if ((match_n_match("<*", str)) == 1)
      return (1);
  if ((match_n_match(">*", str)) == 1)
      return (1);
  if ((match_n_match("|*", str)) == 1)
      return (1);
  if ((match_n_match(";*", str)) == 1)
      return (1);
  if ((match_n_match(">>*", str)) == 1)
      return (1);
  if ((match_n_match("<<*", str)) == 1)
      return (1);
  return (0);
}

t_exe	*insert_node(char **tab)
{
  t_exe	*new;

  if (tab == NULL)
    return (NULL);
  new = malloc(sizeof(t_exe));
  if (new == NULL)
    return (NULL);
  new->data_tab = tab;
  new->left = NULL;
  new->right = NULL;
  return (new);
}

t_exe	*build_list_exec(char **tab, t_exe *elem)
{
  char	**token;

  token = tab;
  while (*tab != NULL)
    {
      tab++;
      if (*tab == NULL || (check_token(*tab)) == 1)
	{
	  elem->right = insert_node(my_realloc_tab(token, 1));
	  elem = elem->right;
	  token++;
	  elem->left = insert_node(my_realloc_tab((token), (tab - token)));
	  if (elem == NULL || elem->left == NULL)
	    return (NULL);
	  token = tab;
	}
    }
  return (elem);
}

t_exe	*exec_list(char **tab)
{
  char	**first;
  t_exe	*first_elem;

  first = tab;
  while (*tab && (check_token(*tab)) != 1)
    tab++;
  first_elem = insert_node((my_realloc_tab(first, tab - first))); 
  if (first_elem == NULL)
    return (NULL);
  if (first_elem->data_tab == NULL)
    return (NULL);
  if (tab != NULL)
    build_list_exec(tab, first_elem);
  return (first_elem);
}
