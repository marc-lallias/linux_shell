/*
** main.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Mon Apr  4 00:15:15 2016 Marc Lallias
** Last update Tue May 24 15:52:25 2016 Marc Lallias
*/

#include "../inc/minishell2.h"
  
int	prep_execution(char *line, t_env **l_env)
{
  t_env	*arg;
  t_exe	*to_do;
  t_put	curr;

  arg = my_argv(line);
  if (arg == NULL)
      return (1);
  to_do = exec_list(arg, *l_env);
  if (to_do == NULL || *(to_do->data_tab) == NULL)
      return (-1);
  to_do = make_graph(to_do);
  if (to_do == NULL)
    return (-1);
  /* to_do = rev_exe_list(to_do); */
  /* if ((match_n_match(*(to_do->dat_tab, '&')) == 1) */
  /*   { */
  /*     untracked_fork(); */
  /*     return (-1); */
  /*   } */
  /* if ((ret = test_exit(to_do->data_tab) != -1) */
  /*   return (-1); */
  /* while (to_do) */
  /*   { */
  /*     printf("\n   CURR:\n"); */
  /*     my_show_tab(to_do->data_tab); */
  /*     if (to_do->left) */
  /* 	{ */
  /* 	  printf("          LEFT:\n"); */
  /* 	  while (to_do->left) */
  /* 	    { */
  /* 	      printf("xxx\n"); */
  /* 	      my_show_tab(to_do->left->data_tab); */
  /* 	      to_do->left = to_do->left->right; */
  /* 	    } */
  /* 	} */
  /*     to_do = to_do->right; */
  /*   } */
  start_put_struct(&curr);
  do_graph(to_do, l_env, &curr);
  /* FREE TO_DO */
  if (curr.exit_stat == NEED_EXIT)
    {
       my_put_str("exit\n");
      exit (curr.ret);
    }
  close_put_struct(&curr);  /* free to_do */
  return (curr.ret);
}

int	prompt(t_env **l_env, char *buff)
{
  char	**argv;
  char	*line;
  int	ret;

  ret = 0;
  my_put_str((getcwd(buff, PATH_MAX)));
  my_put_str(": ");
  while ((line = get_next_line(0)) != NULL)
    {
      ret = prep_execution(line, l_env);
      /* printf("%d\n", ret); */
      my_put_str((getcwd(buff, PATH_MAX)));
      my_put_str(": ");
      free(line);
      /* my_free_tab(argv); */
    }
  my_putchar('\n', 1);
  /* printf("ret: %d\n", ret); */
  return (ret);
}

void	handler(int signal)
{
  return ;
}

int	main(int ac, char **av, char **env)
{
  t_env	*l_env;
  char	buff[PATH_MAX + 1];

  *buff = '\0';
  signal(SIGINT, handler);
  l_env = env_dup(env);
  if (l_env == NULL)
    {
      put_err("Be aware there is not env\n");
    }
  return ((prompt(&l_env, buff)));
}
