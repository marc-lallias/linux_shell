/*
** manipulation_string.c for  in /home/darkmark/perso/my_getenv
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Wed Mar 30 01:14:29 2016 Marc Lallias
** Last update Sun Apr 10 03:19:41 2016 Marc Lallias
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

char	*my_strcopy(char *dest, char *source)
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

char	*my_strcat(char *dest, char *source)
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
      *dest++;
    }
  *dest = '\0';
  return (first);
}
