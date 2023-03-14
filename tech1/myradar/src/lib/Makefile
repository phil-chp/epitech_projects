##
## EPITECH PROJECT, 2021
## my_radar
## File description:
## lib my makefile
##

NAME	=	libmy.a

CP		=	cp -f

RM		=	rm -f

SRC		=	my/my_putstr.c	\
			my/my_strlen.c	\
			my/my_getnbr.c

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
