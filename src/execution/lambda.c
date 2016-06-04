/*
** lambda.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/execution
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Wed Apr  6 01:21:21 2016 Marc Lallias
** Last update Sat Jun  4 17:00:42 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	exec_bin(char **argv, char **env)
{
  if (my_tab_len(argv) >= ARG_MAX)
    {
      put_err(ARG_MAX_ERR);
      return (1);
    }
  if ((access(argv[0], X_OK)) == F_OK)
    return (execve(argv[0], argv, env));
  exit(1);
}

int	exec(char **argv, t_env **l_env,  char **env, t_put *put)
{
  int	ret;

  if (apply_redirection(put) == -1)
    put_err(APPLY_REDIR_ERR);
  if ((ret = build_in(argv, l_env)) != -1)
    exit(EXIT_SUCCESS);
  return (exec_bin(argv, env));
}

int	normal(char **argv, t_env **l_env, t_put *put)
{
  int	pid;
  char	**env;

  env = NULL;
  if ( argv == NULL)
    {
      if (close_father(put) == -1)
	return (-1);
      return (1);
    }
  if ((put->env == ENV) && (env = build_env(*l_env)) == NULL)
    return (1);
  pid = fork();
  if (pid == -1)
    return (1);
  if (pid == 0)
    exec(argv, l_env, env, put);
  else
    {
      my_free_tab(env);
      if (close_father(put) == -1)
	return (1);
    }
  return (pid);
}
