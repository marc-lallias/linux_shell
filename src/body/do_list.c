/*
** exec_list.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/body
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Thu Apr 14 00:33:18 2016 Marc Lallias
** Last update Thu May 26 13:43:29 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"


int	do_list(t_exe *to_do, t_env **l_env, t_put *curr)
{/* plus logique faire recursive si pipe et direct les redirection dedans */
  t_int	*l_pid;
  /* gerer a ce niveau le & */
  /* gere le cas de build in pere ici et faire la recursive de negre (propos humoristique) */
  /* curr->argv = NULL; */
  l_pid = NULL;
  while (to_do)
    {
      if ((match_n_match(*(to_do->data_tab), "|")) == 1 )
	{
	  /* if (curr->argv == NULL) */
	    /* close_father(curr); */
	  /* else */
	  /*   { */
	      l_pid = put_in_int(l_pid);
	      l_pid->data_int = pipe_shell(to_do, l_env, curr);
	    /* } */
	}
      else if ((to_do = choose_token(to_do, l_env, curr)) == NULL)
	return (1);/* faire return int -1 = return 1 */
      if (to_do)
	to_do = to_do->right;
    }
  if (curr->argv != NULL)
    {
      l_pid = put_in_int(l_pid);
      l_pid->data_int = normal(curr->argv, l_env, curr);
    }
  /* while (l_pid) */
  /*   { */
  /*     printf("++%d\n", l_pid->data_int); */
  /*     l_pid = l_pid->next; */
  /*   } */
  init_put_struct(curr);/* pr close pipe devrait faire dns close father */
  return (father_wait(l_pid));
}

int	check_last_token(t_exe *to_do, t_env **l_env, t_put *curr)
{
  int	ret;
  char	**loc_argv;

  if (curr->argv != NULL)
    {
      if ((match_n_match(*(curr->argv), "exit") == 1))
	{
	  loc_argv = curr->argv;
	  do_list(to_do, l_env, curr);
	  curr->ret = my_exit(loc_argv, &ret);
	  if (ret != 1)
	    curr->exit_stat = NEED_EXIT;
	  return (curr->ret);
	}
      if( (match_n_match(*(curr->argv), "echo") == 1) 
	  || (match_n_match(*(curr->argv), "env") == 1)
	  || (match_n_match(*(curr->argv), "setenv") == 1)
	    && (curr->argv[1] == NULL))
    {
      return (do_list(to_do, l_env, curr));
    }
    else if ((curr->argv != NULL) && (check_build_in(*(curr->argv)) == 1))
      {
	loc_argv = curr->argv;
	do_list(to_do, l_env, curr);
	build_in(loc_argv, l_env);
	return (curr->ret);
      }
    }
  return (do_list(to_do, l_env, curr));
}

int    	preli_do_list(t_exe *to_do, t_env **l_env, t_put *curr)
{
  t_int	*l_pid;

  l_pid = NULL;
  while (to_do)
    {
      if (match_n_match(*(to_do->data_tab), "|") == 1)
	{
	  return (check_last_token(to_do, l_env, curr));
	}
      if ((to_do = choose_token(to_do, l_env, curr)) == NULL)
	return (1);/* faire return int -1 = return 1 */
      if (to_do)
	to_do = to_do->right;
    }
  return (check_last_token(to_do, l_env, curr));
}

int	do_graph(t_exe *to_do, t_env **l_env, t_put *curr)
{
  /* printf("curr->ret:  %d\n", curr->ret); */
  while (to_do)
    {
      if ((to_do->data_tab == NULL)
	  || (match_n_match(*(to_do->data_tab), ";") == 1))
	{
	  curr->ret = preli_do_list(to_do->left, l_env, curr);
	  /* free to_do->left */
	}
      else if ((match_n_match(*(to_do->data_tab), "&&") == 1)
	       && (curr->ret == 0))
	{
	  curr->ret = preli_do_list(to_do->left, l_env, curr);
	  /* free to_do->left */
	}
      else if ((match_n_match(*(to_do->data_tab), "||") == 1)
	       && (curr->ret == 1))
	{
	  curr->ret = preli_do_list(to_do->left, l_env, curr);
	  /* free to_do->left */
	}
      init_put_struct(curr);
      to_do = to_do->right;
    }
  /* printf("curr->ret: %d\n", curr->ret); */
  return (curr->ret);
}
