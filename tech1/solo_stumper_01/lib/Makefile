##
## EPITECH PROJECT, 2021
## clean_str
## File description:
## my lib
##

NAME	=	libmy.a

RM		=	rm -f

SRC		=	my_strlen.c	\
			my_putstr.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
