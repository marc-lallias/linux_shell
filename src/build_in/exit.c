/*
** exit.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/build_in
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Tue Apr 12 18:35:25 2016 Marc Lallias
** Last update Fri Jun  3 17:55:06 2016 
*/

#include "../../inc/minishell2.h"

int	my_exit(char **argv, int *err)
{
  int	ret;

  *err = 0;
  ret = my_getnbr(argv[1], err);
  if (*err == 1)
    {
      my_put_str(EXIT_ERR_INPUT);
      return (1);
    }
  return (ret);
}
