/*
** get_next_line.h for  in /home/darkmark/perso
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Tue Mar 29 00:49:32 2016 Marc Lallias
** Last update Tue Mar 29 03:28:29 2016 Marc Lallias
*/

#ifndef GET_NEXT_LINE_H_
# define  GET_NEXT_LINE_H_

#include <stdlib.h>
#include <unistd.h>

#ifndef READ_SIZE
# define READ_SIZE (5)
#endif /* READ_SIZE */

/* get_next_line.c */

char		*concat_line(char *dest, char *source);
char		*get_next_line(const int fd);
int		make_buff(char *buff, char **line, int fd);
int		make_line(char **line, char *buff);
int		strlen_stop(char *str, char c);

#endif  /* GET_NEXT_LINE_H_ */
