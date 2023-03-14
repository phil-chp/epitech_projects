##
## EPITECH PROJECT, 2021
## duostumper2
## File description:
## Makfile lib
##

NAME	=	libmy.a

RM	=	@rm -f

SRC	=	$(wildcard my/*.c)

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $@ $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
