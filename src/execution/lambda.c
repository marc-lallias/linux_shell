/*
** lambda.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/execution
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Wed Apr  6 01:21:21 2016 Marc Lallias
** Last update Thu Apr 28 14:03:51 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

char	*next_path(char *buff, char *try, char *arg1)
{
  char	*first;

  first = buff;
  if (*try)
    {
      while (*try != '\0' && *try != ':')
	{
	  if ((buff - first) >= PATH_MAX - 1)
	    return (NULL);
	  *buff = *try;
	  try++;
	  buff++;
	}
      *buff = '/';
      buff++;
      *buff = '\0';
      if ((buff - first + (my_strlen(arg1))) >= PATH_MAX)
	return (NULL);
      my_strcat(buff, arg1);/* faut strncat */
      try = pass_to(try, ':');
      if (*try)
	  try++;
      return (try);
    }
  return (NULL);
}

int	exec_bin(char **argv, t_env **l_env)
{
  char	buff[PATH_MAX + 1];
  char	*try;
  char	**env;

  *buff = '\0';
  env = build_env(*l_env);
  if (env == NULL)
    exit(EXIT_FAILURE);
  if ((try = my_getenv(*l_env, "PATH")) == NULL)
    {
      put_err("No PATH in env\n");
      exit(EXIT_FAILURE);
    }
  if ((access(argv[0], X_OK)) == F_OK)
    execve(argv[0], argv, env);
  while ((try = next_path(buff, try, argv[0])) != NULL)
    {
      if ((access(buff, X_OK)) == F_OK)
	   execve(buff, argv, env);
    }
  exit(EXIT_FAILURE);
  return (1);
}

int	exec(char **argv, t_env **l_env, t_put *put)
{
  apply_redirection(put);
  return (exec_bin(argv, l_env));
}

int	normal(char **argv, t_env **l_env, t_put *put)
{
  int   child;
  int	pid;
  int	ret;

  
  if ((ret = build_in1(argv, l_env)) != -1)
    return (ret);
  pid = fork();
  if (pid == -1)
    {
      put_err("can't fork\n");
      return (-1);
    }
  if (pid == 0)
    exec(argv, l_env, put);
  else
      {
	int       status;

	close_father(put);
	waitpid(pid, &status, WUNTRACED);
	if (WIFSIGNALED(status))
	  {
	    if (WCOREDUMP(status))
	      put_err("Erreur de segmentation (core dumped).\n");
	}
	return (status);
      }
  return (1);
}
