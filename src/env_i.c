/*
** env_i.c for env_i.c in /home/sentrance/Documents/peixot_a/rendu/PSU/PSU_2015_42sh/src
**
** Made by Pierre Peixoto
** Login peixot_a <pierre.peixoto@epitech.eu>
**
** Started on  Wed Jun  1 16:04:35 2016
** Last update Wed Jun  1 17:43:12 2016 
*/

#include <pwd.h>
#include <sys/types.h>
#include "../inc/minishell2.h"

int		env_i(t_env **l_env)
{
  struct passwd	*pw;

  if ((pw = getpwent()) == NULL)
    return (-1);
  if (((*l_env) = new_change_elem((*l_env), "USER", pw.pw_name)) == NULL)
    return (-1);
  if (((*l_env) = new_change_elem((*l_env), "HOME", pw.pw_dir)) == NULL)
    return (-1);
  if (((*l_env) = new_change_elem((*l_env), "SHELL", pw.pw_shell)) == NULL)
    return (-1);
  free(pw);
  return (0);
}
