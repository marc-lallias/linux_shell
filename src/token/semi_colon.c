/*
** semi_colon.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/token
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu Apr 14 15:32:31 2016 Marc Lallias
** Last update Sat May  7 22:22:32 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"


t_exe	*semi_colon(t_exe *to_do, t_env **l_env, t_put *curr)
{
  
  normal(curr->argv, l_env, curr);
  close_put_struct(curr);
  start_put_struct(curr);
  /* if (to_do->left) */
  /*   { */
  /*     curr->argv = to_do->left->data_tab; */
  /*   } */
  return (to_do);
}
