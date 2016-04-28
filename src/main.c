/*
** main.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Mon Apr  4 00:15:15 2016 Marc Lallias
** Last update Thu Apr 28 13:47:25 2016 Marc Lallias
*/

#include "../inc/minishell2.h"

int	test_exit(char **argv, t_env **l_env, char *line)
{
  int	nb;

  if ((match_n_match("exit", argv[0])) == 1)
    {
      if (argv[1] == NULL)
	{
	  free(line);
	  my_free_tab(argv);
	  free_env(*l_env);
	  return (0);
	}
      if ((nb = my_exit(argv, l_env)) != -1)
	{
	  free(line);
	  my_free_tab(argv);
	  free_env(*l_env);
	}
      else
	put_err("Exit requierre a well syntaxed number.\n");
      return (nb);
    }
  else
    return (-1);
}
  
int	prep_execution(char **argv, t_env **l_env)
{
  t_exe	*to_do;
  t_put	curr[1];

  to_do = exec_list(argv);
  if (to_do == NULL || *(to_do->data_tab) == NULL)
    return (1);
  start_put_struct(curr);
  curr->argv = to_do->data_tab;
  do_list(to_do->right, l_env, curr);
  close_put_struct(curr);
  return (0);
}

int	prompt(t_env **l_env, char *buff)
{
  char	**argv;
  char	*line;
  int	ret;
  
  my_put_str((getcwd(buff, PATH_MAX)));
  my_put_str(": ");
  while ((line = get_next_line(0)) != NULL)
    {
      argv = my_argv(line);
      if (argv != NULL)
      	{
      	  if ((ret = test_exit(argv, l_env, line)) != -1)
	    return (ret);
      	  prep_execution(argv, l_env);
      	}
      free(line);
      my_free_tab(argv);
      my_put_str((getcwd(buff, PATH_MAX)));
      my_put_str(": ");
    }
  my_putchar('\n', 1);
  return (0);
}

void	handler(int signal)
{
  return ;
}

int	main(int ac, char **av, char **env)
{
  char	**argv;
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
