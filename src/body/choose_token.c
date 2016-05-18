/*
** choose_token.c for  in /home/darkmark/rendu/PSU_2015_42sh/src/body
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Sat May 14 18:19:56 2016 Marc Lallias
** Last update Wed May 18 17:04:22 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

t_exe	*handle_executable(t_exe *to_do, t_env *l_env, t_put *curr)
{
  int	ret;

  /*0=uncknow comm -1 err gere 1ok */
  /* printf("PLACE\n"); */
  if (check_build_in(*(to_do->data_tab)) == 1)
    {
      curr->argv = to_do->data_tab;
      return (to_do);
    }
  ret = check_exe(to_do->data_tab, l_env);
  if (ret == 0)
    {
      curr->argv = NULL;
      put_err(*(to_do->data_tab));
      put_err(" : Command not found.\n");
      curr->ret = -1;
      return (to_do);
    }
  else if (ret == -1)
    {
      /* free(first_to_do); */
      curr->argv = NULL;
      return (NULL);
    }
  /* printf("GOOD\n"); */
  curr->argv = to_do->data_tab;
  return (to_do);
}

t_exe	*choose_token(t_exe *to_do, t_env **l_env, t_put *curr)
{
  /* secur pour le to_do->right */
  if (to_do->right != NULL)
    {
      /* if ((match_n_match(*(to_do->data_tab), "|")) == 1) */
      /* 	return ((pipe_shell(to_do, l_env, curr))); */
      if ((match_n_match(*(to_do->data_tab), "<")) == 1)
	return ((left_redir(to_do, l_env, curr)));
      if ((match_n_match(*(to_do->right->data_tab), ">")) == 1)
	return ((right_redir(to_do, l_env, curr)));
      if ((match_n_match(*(to_do->right->data_tab), "<<")) == 1)
	return ((double_redir_left(to_do, l_env, curr)));
      if ((match_n_match(*(to_do->right->data_tab), ">>")) == 1)
	return ((double_redir_right(to_do, l_env, curr)));
    }
  return (handle_executable(to_do, *l_env, curr));
}
