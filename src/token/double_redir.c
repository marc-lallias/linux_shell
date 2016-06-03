/*
** double_redif.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/token
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu Apr 14 22:32:13 2016 Marc Lallias
** Last update Tue May 31 16:46:36 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

t_exe	*double_redir_left(t_exe *to_do, t_env **l_env, t_put *curr)
{
  curr->rr_in = open(*(to_do->data_tab), O_RDWR | O_APPEND);
  if (curr->rr_in == -1)
    {
      curr->argv = NULL;
      put_err(*(to_do->data_tab));
      put_err(" : no such file.\n");
      while (to_do->right
	     && (match_n_match(*to_do->right->data_tab, "|") != 1))
	to_do = to_do->right;
      return (to_do);
    }
  return (to_do->right);
}

t_exe	*double_redir_right(t_exe *to_do, t_env **l_env, t_put *curr)
{
  curr->rr_out = open(*(to_do->data_tab), O_RDWR | O_APPEND | O_CREAT,
		      S_IROTH | S_IRUSR | S_IRGRP | S_IWUSR | S_IWGRP);
  return (to_do->right);
}
