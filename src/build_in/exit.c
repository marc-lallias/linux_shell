/*
** exit.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/build_in
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Tue Apr 12 18:35:25 2016 Marc Lallias
** Last update Thu May 26 13:23:37 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	my_exit(char **argv, int *err)
{
  int	ret;
  int	nb;

  *err = 0;
  ret = my_getnbr(argv[1], err);
  printf("In exit nb: %d  ret: %d\n", ret, *err);
  if (*err == 1)
    {
      my_put_str("Exit: Invalid input.\n");
      return (1);
    }
  return (ret);
}
