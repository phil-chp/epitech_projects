##
## EPITECH PROJECT, 2022
## strace (Workspace)
## File description:
## Makefile
##

NAME	=	libmy.a

RM		=	rm -f

SRC		=	$(wildcard my/*.c)

OBJ		=	$(SRC:.c=.o)

MSG		=	@echo "[\e[32mstrace\e[39m] Compiled 'my' lib succesfully"

all:		$(NAME)
			$(MSG)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
