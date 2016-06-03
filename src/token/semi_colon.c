/*
** semi_colon.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/token
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Thu Apr 14 15:32:31 2016 Marc Lallias
** Last update Fri Jun  3 18:11:54 2016 
*/

#include "../../inc/minishell2.h"


t_exe	*semi_colon(t_exe *to_do, t_env **l_env, t_put *curr)
{

  curr->ret = normal(curr->argv, l_env, curr);
  close_put_struct(curr);
  start_put_struct(curr);
  return (to_do);
}
