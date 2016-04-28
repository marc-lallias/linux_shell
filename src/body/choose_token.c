/*
** choose_token.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/body
c** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Mon Apr 11 20:16:13 2016 Marc Lallias
** Last update Thu Apr 14 23:20:33 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

t_exe	*choose_token(t_exe *to_do, t_env **l_env, t_put *curr)
{
  if (to_do != NULL)
    {
      if ((match_n_match(*(to_do->data_tab), "|")) == 1)
	{
	  return ((pipe_shell(to_do, l_env, curr)));
	}
      if ((match_n_match(*(to_do->data_tab), ";")) == 1)
	{
	  return ((semi_colon(to_do, l_env, curr)));
	}
      if ((match_n_match(*(to_do->data_tab), "<")) == 1)
	{
	  return ((left_redir(to_do, l_env, curr)));
	}
       if ((match_n_match(*(to_do->data_tab), ">")) == 1)
	{
	  return ((right_redir(to_do, l_env, curr)));
	}
      /* if ((match_n_match(*(to_do->data_tab), ">>")) == 1) */
      /* 	{ */
      /* 	  return ((double_redir_right(to_do, l_env, curr))); */
      /* 	} */
   }
  put_err("Wrong commande\n");
  return (NULL);
}
