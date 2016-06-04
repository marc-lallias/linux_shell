/*
1;4205;0c** match_n_match.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Mon Apr  4 00:34:48 2016 Marc Lallias
** Last update Sat Jun  4 15:45:57 2016 Marc Lallias
*/

#include "../inc/minishell2.h"

int     match_complet(char *to_find, char *find_in)
{
  while ((*to_find == *find_in) && *to_find && *find_in)
    {
      to_find++;
      find_in++;
    }
  if (*to_find == '\0' && *find_in == '\0')
    return (1);
  return (0);
}

int	match(char *to_find, char *find_in)
{
  while ((*to_find == *find_in) && *to_find && *find_in)
    {
      to_find++;
      find_in++;
      if (*to_find == '\0')
	return (1);
    }
  return (0);
}

int	match_n_match(char *to_find, char *find_in)
{
  if ((to_find[0] == '\0' && find_in[0] == '\0') ||
      (to_find[0] == '*' && to_find[1] == '\0'))
    return (1);
  else if (find_in[0] == '\0' || to_find[0] == '\0')
    return (0);
  else if (to_find[0] == '*')
    {
      if (match_n_match(&(to_find[1]), &(find_in[0])) == 1)
	return (1);
      else
	return (match_n_match(&(to_find[0]), &(find_in[1])));
    }
  else if (to_find[0] == find_in[0])
    return (match_n_match(&(to_find[1]), &(find_in[1])));
  else
    return (0);
}
