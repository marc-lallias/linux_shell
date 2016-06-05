/*
** get_next_line.h for  in /home/darkmark/perso
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Tue Mar 29 00:49:32 2016 Marc Lallias
** Last update Sun Jun  5 17:57:16 2016 Marc Lallias
*/

#ifndef GET_NEXT_LINE_H_
# define  GET_NEXT_LINE_H_

#include <stdlib.h>
#include <unistd.h>

#ifndef READ_SIZE
# define READ_SIZE (5)
#endif /* !READ_SIZE */

/*
** Get next line functions
*/

char		*get_next_line(const int fd);

#endif  /* !GET_NEXT_LINE_H_ */
