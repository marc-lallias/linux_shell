/*
** manipulation_string.c for  in /home/darkmark/perso/my_getenv
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Wed Mar 30 01:14:29 2016 Marc Lallias
** Last update Sat Jun  4 16:45:02 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	my_strlen(char *str)
{
  char	*first;

  if (str == NULL)
    return (0);
  first = str;
  while (*str)
      str++;
  return (str - first);
}

char	*my_strcopy(char *dest, char const *source)
{
  char	*first;

  if (source == NULL)
    return (NULL);
  first = dest;
  while (*source)
    {
      *dest = *source;
      source++;
      dest++;
    }
  *dest = '\0';
  return (first);
}

char	*my_strcat(char *dest, const char *source)
{
  char	*first;

  if (source == NULL)
    return (NULL);
  first = dest;
  while (*dest)
      dest++;
  while (*source)
    {
      *dest = *source;
      source++;
      dest++;
    }
  *dest = '\0';
  return (first);
}

char	*my_str_n_copy(char *dest, const char *source, int size)
{
  char	*first;

  if (source == NULL)
    return (NULL);
  first = dest;
  while (*source && (size > 0))
    {
      *dest = *source;
      source++;
      dest++;
      size--;
    }
  *dest = '\0';
  return (first);
}
