/*
** my_getnbr.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/tools
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Tue Apr 12 18:39:56 2016 Marc Lallias
** Last update Wed Apr 13 15:09:22 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	my_getnbr(char *str)
{
  int	tot;

  tot = 0;
  if (str == NULL)
    return (0);
  if (*str == '0')
    return (-1);
  while (*str)
    {
      if (*str <= '0' || *str >= '9')
	return (-1);
      tot = tot * 10 + (*str - '0');
      str++;
    }
  return (tot);
}
