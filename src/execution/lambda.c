/*
** lambda.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/execution
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Wed Apr  6 01:21:21 2016 Marc Lallias
** Last update Mon May  9 14:23:07 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	exec_bin(char **argv, t_env **l_env)
{
  /* char	buff[PATH_MAX + 1]; */
  char	*try;
  char	**env;

  /* *buff = '\0'; */
  if ((access(argv[0], X_OK)) == F_OK) /* check ARG_MAX */
    execve(argv[0], argv, env);
  /* env = build_env(*l_env); */
  /* if (env == NULL) */
  /*   exit(EXIT_FAILURE); */
  /* if ((try = my_getenv(*l_env, "PATH")) == NULL) */
  /*   { */
  /*     put_err("No PATH in env\n"); */
  /*     exit(EXIT_FAILURE); */
  /*   } */
  /* while ((try = next_path(buff, try, argv[0])) != NULL) */
  /*   { */
  /*     if ((access(buff, X_OK)) == F_OK) */
  /* 	  execve(buff, argv, env); */
  /*   } */
  /* put_err(argv[0]); */
  /* put_err(" : commande introuvable\n"); */
  /* exit(EXIT_FAILURE); */
  return (1);
}

int	exec(char **argv, t_env **l_env, t_put *put)
{
  int	ret;

  /* printf("la\n"); */
  /* exit(42); */
  apply_redirection(put);/* gestion dup si return -1 aff dup fail */
  if ((ret = build_in_child(argv, l_env)) != -1)
    exit(EXIT_SUCCESS);
  return (exec_bin(argv, l_env));
}

int	father(int pid, t_put *put)
{
  int       status;

  close_father(put);
  waitpid(pid, &status, WUNTRACED);
  if (WIFSIGNALED(status))
    {
      if (WCOREDUMP(status))
	{
	  put_err("Erreur de segmentation (core dumped).\n");
	  return (1);/* SIGUSR TRUC */
	}
    }
  /* printf("retour de l'execve: %d\n", WEXITSTATUS(status)); */
  return (WEXITSTATUS(status));
}

int	normal(char **argv, t_env **l_env, t_put *put)
{
  int   child;
  int	pid;
  int	ret;

  if ((ret = build_in_father(argv, l_env)) != -1)
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
    return (father(pid, put));
  return (1);
}
