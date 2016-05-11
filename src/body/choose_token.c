/*
** choose_token.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/body
c** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Mon Apr 11 20:16:13 2016 Marc Lallias
** Last update Wed May 11 00:27:31 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

t_exe	*choose_token(t_exe *to_do, t_env **l_env, t_put *curr)
{
  if ((match_n_match(*(to_do->data_tab), "|")) == 1)
    return ((pipe_shell(to_do, l_env, curr)));
  if ((match_n_match(*(to_do->data_tab), ";")) == 1)
    return ((semi_colon(to_do, l_env, curr)));
  if ((match_n_match(*(to_do->data_tab), "<")) == 1)
    return ((left_redir(to_do, l_env, curr)));
  if ((match_n_match(*(to_do->data_tab), ">")) == 1)
    return ((right_redir(to_do, l_env, curr)));
  if ((match_n_match(*(to_do->data_tab), "<<")) == 1)
    return ((double_redir_left(to_do, l_env, curr)));
  if ((match_n_match(*(to_do->data_tab), ">>")) == 1)
    return ((double_redir_right(to_do, l_env, curr)));
  if ((check_build_in(*(to_do->data_tab)) == 1)
      || (check_exe(&(*(to_do->data_tab)), *l_env) == 1))
    curr->argv = to_do->data_tab;
  else
    {
      put_err(*(to_do->data_tab));
      put_err(": Command not found.\n");
      curr->ret = 1;
      return (NULL);
    }
  return (to_do);
}
