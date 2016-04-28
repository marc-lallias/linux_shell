/*
1;4002;0c** get_next_line.c for  in /home/darkmark/perso
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Tue Mar 29 00:48:49 2016 Marc Lallias
** Last update Sun Apr 10 19:47:59 2016 Marc Lallias
*/

#include "../../inc/get_next_line.h"

int		strlen_stop(char *str, char c)
{
  char		*first;

  if (str == NULL)
    return (0);
  first = str;
  while (*str)
    {
      if (*str == c)
	return ((str - first) + 1);
      str++;
    }
  return (str - first);
}

char		*concat_line(char *dest, char *source)
{
  while (*source)
    {
      *dest = *source;
      if (*source == '\n')
	{
	  *dest = '\0';
	  return (dest);
	}
      source++;
      dest++;
    }
  *dest = '\0';
  return (dest);
}

int		make_line(char **line, char *buff)
{
  char		*first;
  char		*new;
  int		buff_rest;

  if (*buff == '\0')
    return (0);
  buff_rest = strlen_stop(buff, '\n');
  new = malloc((strlen_stop(*line, '\0')) + buff_rest + 1);
  if (new == NULL)
    return (-1);
  first = new;
  if (*line != NULL)
    {
      new = concat_line(new, *line);
      free(*line);
      *line = NULL;
    }
  concat_line(new, buff);
  *line = first;
  return (buff_rest);
}

int		make_buff(char *buff, char **line, int fd)
{
  int		ret;

  ret = read(fd, buff, READ_SIZE);
  buff[ret] = '\0';
  if (ret == -1)
    {
      free(*line);
      *line = NULL;
    }
  if (ret == 0)
    {
      if ((*line != NULL) && fd == 0)
	{
	  free(*line);
	  *line = NULL;
	}
    }
  return (ret);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1];
  static int	i_b = 0;
  char          *line;
  int		ret;
  
  line = NULL;
  if (*buff == '\0')
    {
      if ((make_buff(buff, &line, fd)) <= 0)
	return (line);
    }
  while (i_b == 0 || line == NULL)
    {
      if ((ret = make_line(&line, &buff[i_b])) == -1)
	return (NULL);
      i_b = i_b + ret;
      if ((buff[i_b - 1]) == '\n' && line)
	  return (line);
      if ((make_buff(buff, &line, fd)) <= 0)
	  return (line);
      i_b = 0;
    }
}
