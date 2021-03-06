/*
** aff.c for  in /home/darkmark/rendu/PSU_2015_minishell2/env
**
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
**
** Started on  Wed Mar 30 16:15:33 2016 Marc Lallias
** Last update Sun Jun  5 18:12:54 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int	aff_env_list(const t_env *l_env)
{
  if (l_env)
    {
      aff_env_list(l_env->next);
      my_put_str(l_env->data);
      my_putchar('\n', 1);
    }
  else
    return (1);
  return (0);
}

void	my_putchar(const char c, int outpout)
{
  write(outpout, &c, outpout);
}

void	my_put_str(char *str)
{
  if (str == NULL)
    return ;
  write(1, str, my_strlen(str));
}

void	my_show_tab(char **tab)
{
  if (tab == NULL)
    return ;
  while (*tab)
    {
      my_put_str(*tab);
      my_putchar('\n', 1);
      tab++;
    }
}

void	put_err(char *str)
{
  if (str == NULL)
    return ;
  write(2, str, (my_strlen(str)));
}
