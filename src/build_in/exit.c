/*
** exit.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/build_in
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Tue Apr 12 18:35:25 2016 Marc Lallias
** Last update Wed Apr 13 15:36:24 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	my_exit(char **argv, t_env **l_env)
{
  int	nb;

  return (my_getnbr(argv[1]));
}
