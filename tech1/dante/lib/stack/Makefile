##
## EPITECH PROJECT, 2021
## dante (Workspace)
## File description:
## Makefile
##

NAME	=	../libstack.a

RM		=	rm -f

SRC		=	$(wildcard *.c)

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
