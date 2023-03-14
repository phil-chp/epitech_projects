##
## EPITECH PROJECT, 2020
## pushswap (Workspace)
## File description:
## Makefile
##

NAME	=	libmy.a

RM		=	rm -f

SRC		=	lib/my_putchar.c			\
			lib/my_putnbr.c				\
			lib/my_putstr.c				\
			lib/my_strlen.c				\
			lib/my_getnbr.c				\

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
