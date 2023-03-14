##
## EPITECH PROJECT, 2020
## Antman
## File description:
## Lib Makefile
##

NAME	=	liblprintf.a

RM		=	rm -f

SRC		=	my_lprintf/my_lprintf.c

UTILS	=	my/my_putchar.c			\
			my/my_putnbr.c			\
			my/my_putstr.c			\
			my/my_strlen.c			\
			my/my_put_tbl.c			\
			my/my_getnbr.c			\
			my/my_revstr.c			\
			my/my_strcmp.c			\
			my/my_strcpy.c			\
			my/my_strdup.c			\
			my_lprintf/my_lprintf.c

OBJ		=	$(SRC:.c=.o) $(UTILS:.c=.o)

all:		$(NAME)
			ar rc $(NAME) $(OBJ)

$(NAME):	$(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
