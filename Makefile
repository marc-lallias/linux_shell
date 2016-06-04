##
## Makefile for  in /home/darkmark/rendu/PSU_2015_minishell2
## 
## Made by Marc Lallias
## Login   <lallia_m@epitech.net>
## 
## Started on  Sun Apr  3 23:58:58 2016 Marc Lallias
## Last update Sat Jun  4 23:51:38 2016 Marc Lallias
##

NAME	=	42sh

SRC	=	./src/main.c				\
		./src/aff/aff.c				\
		./src/body/build_in1.c			\
		./src/body/choose_token.c		\
		./src/body/do_list.c			\
		./src/body/leav.c			\
		./src/build_in/cd.c			\
		./src/build_in/my_echo.c		\
		./src/build_in/exit.c			\
		./src/build_in/setenv.c			\
		./src/build_in/unsetenv.c		\
		./src/execution/apply_redirection.c	\
		./src/execution/check_exe.c		\
		./src/execution/father_wait.c		\
		./src/execution/lambda.c		\
		./src/execution/make_graph.c		\
		./src/execution/parsing_token.c		\
		./src/free.c				\
		./src/list.c				\
		./src/manipulation/manip_tab1.c		\
		./src/manipulation/manip_string1.c	\
		./src/match_n_match.c			\
		./src/new_getnextline/get_next_line.c	\
		./src/shell_tools/change_env.c		\
		./src/shell_tools/env.c			\
		./src/shell_tools/my_arg.c		\
		./src/shell_tools/shell_tools.c		\
		./src/tools/my_getnbr.c			\
		./src/token/check.c			\
		./src/token/double_redir.c		\
		./src/token/init_put_struct.c		\
		./src/token/pipe.c			\
		./src/token/semi_colon.c		\
		./src/token/simple_redirection.c	\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

CFLAGS	+=	-W -Wall -Wextra

RM	=	rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
