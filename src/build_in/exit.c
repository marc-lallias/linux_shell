/*
** exit.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/build_in
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Tue Apr 12 18:35:25 2016 Marc Lallias
** Last update Wed May 11 00:00:36 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	my_exit(char **argv, t_env **l_env)
{
  int	nb;

  my_put_str("exit\n");
  exit(my_getnbr(argv[1]));
  return (1);
}
