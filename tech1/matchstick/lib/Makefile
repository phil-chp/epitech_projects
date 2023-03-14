##
## EPITECH PROJECT, 2021
## matchstick
## File description:
## Makefile
##

NAME	=	libmy.a

RM		=	rm -f

SRC		=	$(wildcard my/*.c)		\
			$(wildcard pers/*.c)

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
