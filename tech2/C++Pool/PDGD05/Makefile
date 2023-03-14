##
## EPITECH PROJECT, 2022
## PDG-D5 (Workspace)
## File description:
## Makefile
##

NAME	=	libstring.a

RM		=	rm -f

SRC		=	$(wildcard d5/*.c)

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
