/*
** check_exe.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/execution
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Fri May  6 21:11:00 2016 Marc Lallias
** Last update Sun Jun  5 18:28:26 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

char	*next_path(char *buff, char *try, char *arg1)
{
  char	*first;

  first = buff;
  if ((try == NULL) || (*try != '\0'))
    {
      while ((*try != '\0') && (*try != ':'))
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
      if ((buff - first + (my_strlen(arg1))) >= PATH_MAX - 1)
	return (NULL);
      my_strcat(buff, arg1);
      try = pass_to(try, ':');
      if (*try)
	try++;
      return (try);
    }
  return (NULL);
}

int	char_in(char to_found, char *found_in)
{
  while (*found_in)
    {
      if (to_found == *found_in)
	return (1);
      found_in++;
    }
  return (0);
}

int	try_all_path(char **str, t_env *l_env)
{
  char	buff[PATH_MAX + 1];
  char	*try;

  if ((try = my_getenv(l_env, PATH)) == NULL)
    {
      put_err(PATH_NOT_FOUND);
      return (-1);
    }
  while ((try = next_path(buff, try, *str)))
    {
      if ((access(buff, X_OK)) == F_OK)
	{
	  free(*str);
	  if ((*str = malloc((my_strlen(buff)) + 1)) == NULL)
	    return (-1);
	  *str = my_strcopy(*str, buff);
	  return (1);
	}
    }
  return (0);
}

int		check_exe(char **str, t_env *l_env)
{
  struct stat	buff;

  if (char_in('/', *str) == 1)
    {
      if ((stat(*str, &buff)) == 0)
	{
	  if ((S_ISREG(buff.st_mode)))
	    {
	      if ((access(*str, X_OK)) != F_OK)
		{
		  put_err(*str);
		  put_err(NO_EXEC_RIGHT);
		  return (2);
		}
	      return (1);
	    }
	}
    }
  return (try_all_path(str, l_env));
}
