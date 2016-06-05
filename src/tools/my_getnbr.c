/*
** my_getnbr.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/tools
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Tue Apr 12 18:39:56 2016 Marc Lallias
** Last update Sun Jun  5 21:56:05 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	my_getnbr(char *str, int *ret)
{
  int	tot;
  int	sign;

  tot = 0;
  sign = 1;
  if (str == NULL)
    return (0);
  if (*str == '-')
    {
      sign = -1;
      str++;
    }
  while (*str)
    {
      if ((tot >= INT_MAX / 10) || (*str < '0' || *str > '9'))
	{
	  *ret = 1;
	  return (-1);
	}
      tot = tot * 10 + (*str - '0');
      str++;
    }
  return (tot * sign);
}
