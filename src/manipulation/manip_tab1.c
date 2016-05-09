/*
1;4205;0c** manip_tab1.c for  in /home/darkmark/rendu/PSU_2015_minishell2/env
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Sun Apr  3 23:11:29 2016 Marc Lallias
** Last update Thu Apr 28 16:10:19 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

char	**my_realloc_tab(char **tab, int size)
{
  char	**first;
  char	**new_tab;

  if (size == 0)
    return (NULL);
  new_tab = malloc(sizeof(char *) * (size + 1));
  if (tab == NULL)
    return (NULL);
  first = new_tab;
  while (size > 0 && *tab != NULL)
    {
      //printf("\n++ %s\n", *tab);
      *new_tab = *tab;
      new_tab++;
      tab++;
      size--;
    }
  *new_tab = NULL;
  return (first);
}

void	my_free_tab(char **tab)
{
  char	**first;

  first = tab;
  if (tab == NULL)
    return ;
  while (*tab)
    {
      free(*tab);
      tab++;
    }
  free(first);
  return ;
}
