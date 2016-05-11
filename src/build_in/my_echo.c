/*
** my_echo.c for  in /home/darkmark/rendu/PSU_2015_42sh/src/build_in
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Tue May 10 21:36:37 2016 Marc Lallias
** Last update Wed May 11 00:03:37 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	my_echo(char **argv, t_env **l_env)
{
  if (argv == NULL)
    return (1);
  argv++;
  while (*argv)
    {
      put_err(*argv);
      argv++;
    }
  my_put_str("\n");
  return (0);
}
