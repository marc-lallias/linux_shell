/*
** cd.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/build_in
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Mon Apr  4 21:09:32 2016 Marc Lallias
** Last update Mon Apr 11 15:50:04 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	move(char *to_go, t_env **l_env)
{
  char	*pwd;
  char	buff[PATH_MAX + 1];

  if(access(to_go, F_OK | R_OK) == -1)
    {
      put_err("No access\n");
      return (0);
    }
  pwd = getcwd(buff, PATH_MAX);
  if ((chdir(to_go)) == -1)
    {
      put_err("Repository dosn't exist.\n");
      return (0);
    }  
  change_env(l_env, "OLDPWD", pwd);
  pwd = getcwd(buff, PATH_MAX);
  change_env(l_env, "PWD", pwd);
  return (1);
}

char	*concat_home(char *str, t_env *l_env, char *buff)
{
  char	*home;

  home = my_getenv(l_env, "HOME");
  if (str[1] == '/')
  {
    my_strcopy(buff, home);
    my_strcat(buff, str + 1);
    return (buff);
  }
  return (home);
}

int	my_cd(char **argv, t_env **l_env)
{
  char	*to_go;
  char	buff[PATH_MAX];

  if (argv[1] == NULL)
    return (0);
  if ((argv[1])[0] == '~')
    to_go = concat_home(argv[1], *l_env, buff);
  else if ((argv[1])[0] == '-')
    to_go = my_getenv(*l_env, "OLDPWD");
  else if (argv[1] != NULL)
    to_go = argv[1];
  if (to_go == NULL || *to_go == '\0')
    {
      free(to_go);
      put_err("No information in env.\n");
      return (0);
    }
  return (move(to_go, l_env));
}
