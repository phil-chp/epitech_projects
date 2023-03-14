##
## EPITECH PROJECT, 2020
## pushswap
## File description:
## Makefile
##

NAME	=	push_swap

TEST	=	unit_tests

CC		=	gcc

RM		=	rm -f

SRC		=	src/main.c				\
			src/sorter.c			\
			src/link/link_add.c		\
			src/link/link_destroy.c	\
			src/link/link_build.c	\
			src/link/link_remove.c	\
			src/sorting_algo.c		\
			src/val/val_swap.c		\
			src/val/val_move.c		\
			src/val/val_rotate.c	\

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-I./includes/ -L./src/ -lmy -W -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./src/ all
			$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
			$(RM) $(OBJ)
			make -C ./src/ clean
			$(RM) *.vgcore
			$(RM) **/*.gcno
			$(RM) **/*.gcda
			$(RM) index.htm

fclean:		clean
			$(RM) $(NAME)
			make -C ./src/ fclean

re:			fclean all
			make -C ./src/ re

.PHONY:		all clean fclean re
