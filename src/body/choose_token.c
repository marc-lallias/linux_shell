/*
** choose_token.c for  in /home/darkmark/rendu/PSU_2015_42sh/src/body
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Sat May 14 18:19:56 2016 Marc Lallias
** Last update Fri Jun  3 06:10:02 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

t_exe	*handle_check_exe_ret(t_exe *to_do, t_env *l_env, t_put *curr, int ret)
{
  if (ret == 0 || 2)
    {
      curr->argv = NULL;
      if (ret == 0)
	{
	  put_err(*(to_do->data_tab));
	  put_err(": Command not found.\n");
	}
      curr->ret = 1;
      while (to_do && (match_n_match(*to_do->data_tab, "|") != 1))
	to_do = to_do->right;
      return (to_do);
    }
  if (ret == -1)
    {
      /* free(first_to_do); */
      curr->ret = 1;
      curr->argv = NULL;
      return (NULL);
    }
  return (NULL);
}

t_exe	*handle_executable(t_exe *to_do, t_env **l_env, t_put *curr)
{
  int	ret;

  if (match_n_match(*(to_do->data_tab), "env"))
    {
      if (to_do->data_tab[1] && match_n_match((to_do->data_tab)[1], "-i"))
	{
	  free(to_do->data_tab[0]);
	  to_do->data_tab[0] = NULL;
	  free(to_do->data_tab[1]);
	  to_do->data_tab[1] = NULL;
	  to_do->data_tab = &(to_do->data_tab[2]);
	  curr->env = NO_ENV;
	}
    }
  if (check_build_in(*(to_do->data_tab)) != 1)
    {
      ret = check_exe(to_do->data_tab, *l_env);
      if (ret != 1)
	handle_check_exe_ret(to_do, *l_env, curr, ret);
    }
  curr->argv = to_do->data_tab;
  return (to_do);
}

t_exe	*choose_token(t_exe *to_do, t_env **l_env, t_put *curr)
{
  if (to_do->right != NULL)
    {
      if ((match_n_match(*(to_do->right->data_tab), "<")) == 1)
	return ((left_redir(to_do, l_env, curr)));
      if ((match_n_match(*(to_do->right->data_tab), ">")) == 1)
	return ((right_redir(to_do, l_env, curr)));
      if ((match_n_match(*(to_do->right->data_tab), "<<")) == 1)
	return ((double_redir_left(to_do, l_env, curr)));
      if ((match_n_match(*(to_do->right->data_tab), ">>")) == 1)
	return ((double_redir_right(to_do, l_env, curr)));
    }
  return (handle_executable(to_do, l_env, curr));
}
