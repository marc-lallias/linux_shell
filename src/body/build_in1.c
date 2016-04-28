/*
** build_in1.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/body
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Mon Apr  4 13:51:51 2016 Marc Lallias
** Last update Thu Apr 28 13:57:23 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	build_in1(char **argv, t_env **l_env)
{
  if ( argv != NULL)
    {
      if ((match_complet(argv[0], "setenv")) == 1)
	return ((my_setenv(argv, l_env)));
      if ((match_complet(argv[0], "unsetenv")) == 1)
	return ((my_unsetenv(argv, l_env)));
      if ((match_complet(argv[0], "env")) == 1)
	  return ((aff_env_list(*l_env)));
      if ((match_complet(argv[0], "cd")) == 1)
	return ((my_cd(argv, l_env)));
    }
  return (-1);
}
