##
## EPITECH PROJECT, 2021
## n4s (Workspace)
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	libmy.a

RM			=	rm -f

SRC			=	$(wildcard my/*.c)

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
				ar rc $(NAME) $(OBJ)

clean:
				$(RM) $(OBJ)

fclean:
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
