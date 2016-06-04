/*
1;4205;0c** check.c for  in /home/darkmark/rendu/PSU_2015_minishell2/src/token
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Sun May  1 15:43:15 2016 Marc Lallias
** Last update Sat Jun  4 17:16:04 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"

int     check_signifiant(char *str)
{
  if (str == NULL)
    return (1);
  if ((match_n_match("&&", str)) == 1)
    return (1);
  if ((match_n_match("||", str)) == 1)
    return (1);
  if ((match_n_match(";", str)) == 1)
    return (1);
  return (0);

}

int     check_spliters(char *str)
{
  if (str == NULL)
    return (1);
  if ((match_n_match("&&", str)) == 1)
    return (1);
  if ((match_n_match("||", str)) == 1)
    return (1);
  if ((match_n_match("|", str)) == 1)
    return (1);
  if ((match_n_match(";", str)) == 1)
    return (1);
  return (0);
}

int	check_redir(char *str)
{
  if ((match_n_match(">>*", str)) == 1)
    return (1);
  if ((match_n_match("<<*", str)) == 1)
    return (1);
  if ((match_n_match("<*", str)) == 1)
    return (1);
  if ((match_n_match(">*", str)) == 1)
    return (1);
  return (0);
}

int     check_token(char *str)
{
  if ((match_n_match("&&*", str)) == 1)
    return (2);
  if ((match_n_match("||*", str)) == 1)
    return (2);
  if ((match_n_match(">>*", str)) == 1)
    return (2);
  if ((match_n_match("<<*", str)) == 1)
    return (2);
  if ((match_n_match("<*", str)) == 1)
    return (1);
  if ((match_n_match(">*", str)) == 1)
    return (1);
  if ((match_n_match("|*", str)) == 1)
    return (1);
  if ((match_n_match(";*", str)) == 1)
    return (1);
  return (0);
}
