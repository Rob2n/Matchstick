##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## the makefile
##

SRC	=	src/board_handle.c	\
		src/input_handle.c	\
		src/other.c	\
		src/my_putchar.c	\
		src/my_put_nbr.c	\
		src/get_next_line.c	\
		src/my_str_isnum.c	\
		src/main.c	\
		src/my_getnbr.c

CFLAGS	=	-W -Wall -Wextra -g3

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
