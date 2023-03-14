##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Library builder makefile
##

SRC		=	$(wildcard my/*.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
