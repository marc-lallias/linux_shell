/*
** make_graph.c for  in /home/darkmark/rendu/PSU_2015_42sh/src/execution
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu May 12 14:34:51 2016 Marc Lallias
** Last update Sat Jun  4 17:20:35 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

static t_exe		*make_graph_next(t_exe **graph, t_exe **elem,
					 t_exe **previous, t_exe **list)
{
  if ((*list == NULL) || ((check_signifiant(*(*list)->data_tab) == 1)
      && (*((*list)->data_tab + 1) == NULL)))
    {
      (*graph)->left = *elem;
      (*previous)->right = NULL;
      if (*list)
	{
	  (*graph)->data_tab = (*list)->data_tab;
	  if ((*graph = put_in_exe(*graph))  == NULL)
	    return (NULL);
	  *elem = (*list)->right;
	}
      else
	(*graph)->data_tab = NULL;
      return (*list);
    }
  return (NULL);
}

t_exe			*make_graph(t_exe *list)
{
  t_exe			*graph;
  t_exe			*elem;
  t_exe			*previous;
  t_exe			*to_free;

  to_free = NULL;
  if ((graph = put_in_exe(NULL)) == NULL)
    return (NULL);
  elem = list;
  while (list)
    {
      previous = list;
      list = list->right;
      free(to_free);
      to_free = NULL;
      to_free = make_graph_next(&graph, &elem, &previous, &list);
      if  (graph == NULL)
	return (NULL);
    }
  return (graph);
}
