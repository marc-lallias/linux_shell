/*
** father_wait.c for  in /home/darkmark/rendu/PSU_2015_42sh/src/execution
** 
** Made by Marc Lallias
** Login   <lallia_m@epitech.net>
** 
** Started on  Wed May 18 13:58:00 2016 Marc Lallias
** Last update Wed May 18 14:39:07 2016 Marc Lallias
*/

#include "../../inc/minishell2.h"


  /* int       status; */
  /* int           i; */

  /* i = 0; */
  /* while (wait(&status) > 0)/\* , WUNTRACED *\/ */
  /*   { */
  /*     if (WIFSIGNALED(status)) */
  /* 	{ */
  /* 	  if (WCOREDUMP(status)) */
  /* 	    { */
  /* 	      put_err("Erreur de segmentation (core dumped).\n"); */
  /* 	      return (1);/\* SIGUSR TRUC *\/ */
  /* 	    } */
  /* 	} */
  /*     /\* printf("retour de l'execve: %d\n", WEXITSTATxUS(status)); *\/ */
  /*     printf("ret num: %d\n", (WEXITSTATUS(status))); */
  /*   } */
  /* return (0); */

int	father_wait(t_int *l_pid)
{
  int	status;
  int	ret;
  
  status = 0;
  ret = 1;
  while (l_pid)
    {
      waitpid(l_pid->data_int, &status, WUNTRACED);
      if (WIFSIGNALED(status))
  	{
  	  if (WCOREDUMP(status))
  	    {
  	      put_err("Erreur de segmentation (core dumped).\n");
  	      ret = 1;/* SIGUSR TRUC */
  	    }
  	}
      ret = WEXITSTATUS(status);
      l_pid = l_pid->next;
    }
  return (ret);
}
