/*
** make_graph.c for  in /home/darkmark/rendu/PSU_2015_42sh/src/execution
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu May 12 14:34:51 2016 Marc Lallias
** Last update Sat May 14 18:37:15 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

/* t_exe		*graph; */
/* t_exe		*last; */
/* t_exe		*previus; */

/* graph = NULL; */
/* /\* graph = put_in_exe(graph); *\/ */
/* /\* graph->left = list;   *\/ */
/* /\* graph = put_in_exe(graph); *\/ */
/* /\* graph->data_tab = NULL; *\/ */
/* /\* graph->left = list; *\/ */
/* previus = list; */
/* last = list; */
/* while (list) */
/*   { */
/*     if ((list->data_tab == NULL) || */
/* 	  (check_signifiant(*(list->data_tab)) == 1)) */
/* 	{ */
/* 	  graph = put_in_exe(graph); */
/* 	  graph->data_tab = list->data_tab; */
/* 	  last->right = NULL; */
/* 	  graph->left = list->right; */
/* 	  previus = list; */
/* 	} */
/*     last = list; */
/*     list = list->right; */
/*   } */
/* return (graph); */

t_exe		*make_graph(t_exe *list)
{
  t_exe		*graph;
  t_exe		*elem;
  t_exe		*previus;

  if ((graph = put_in_exe(NULL)) == NULL)
    return (NULL);
  elem = list;
  while (list)
    {
      previus = list;
      list = list->right;
      if ((list == NULL) || (check_signifiant(*(list->data_tab)) == 1)
	  && (*(list->data_tab + 1) == NULL))
	{
	  graph->left = elem;
	  previus->right = NULL;
	  if (list)
	    {
	      graph->data_tab = list->data_tab;
	      if ((graph = put_in_exe(graph))  == NULL)
		return (NULL);
	      elem = list->right;
	    }
	  else
	    graph->data_tab = NULL; 
	}
    }
  return (graph);
}
