/*
** cd.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/build_in
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Mon Apr  4 21:09:32 2016 Marc Lallias
** Last update Fri Jun  3 17:54:00 2016 
*/

#include "../../inc/minishell2.h"

int		do_move(char *to_go, struct stat st)
{
  if (S_ISDIR(st.st_mode))
    {
      if ((chdir(to_go)) == -1)
	{
	  put_err(CHDIR_FAIL);
	  return (1);
	}
      return (0);
    }
  if (S_ISREG(st.st_mode))
    {
      put_err(NOR_FILE_DIR);
      return (1);
    }
  else
    {
      put_err(NOR_FILE_DIR);
      return (1);
    }
  return (0);
}

int		move(char *to_go, t_env **l_env)
{
  struct stat	st;
  char		*pwd;
  char		buff[PATH_MAX + 1];

  if ((stat(to_go, &st)) >= 1)
    return (1);
  if ((pwd = getcwd(buff, PATH_MAX)) == NULL)
    {
      put_err(GETCWD_FAIL);
      return (1);
    }
  if (do_move(to_go, st) == 1)
    return (1);
  if (change_env(l_env, OLDPWD, pwd) == -1)
    return (1);
  if ((pwd = getcwd(buff, PATH_MAX)) == NULL)
    {
      put_err(GETCWD_FAIL);
      return (1);
    }
  if (change_env(l_env, PWD, pwd) == -1)
    return (1);
  return (0);
}

char		*concat_home(char *str, t_env *l_env, char *buff)
{
  char		*home;

  home = my_getenv(l_env, HOME);
  if (str[1] == '/')
    {
      my_strcopy(buff, home);
      my_strcat(buff, str + 1);
      return (buff);
    }
  return (home);
}

int		my_cd(char **argv, t_env **l_env)
{
  char		*to_go;
  char		buff[PATH_MAX];

  if (argv[1] == NULL)
    return (1);
  if ((argv[1])[0] == '~')
    to_go = concat_home(argv[1], *l_env, buff);
  else if ((argv[1])[0] == '-')
    to_go = my_getenv(*l_env, OLDPWD);
  else if (argv[1] != NULL)
    to_go = argv[1];
  if (to_go == NULL || *to_go == '\0')
    {
      free(to_go);
      put_err(ENV_NO_INFO);
      return (0);
    }
  return (move(to_go, l_env));
}
