##
## EPITECH PROJECT, 2022
## Project
## File description:
## Makefile Lib
##

NAME		=	my

LIB_NAME	=	lib$(NAME).a

RM			=	rm -f

SRC			=	$(wildcard $(NAME)/*.c)

OBJ			=	$(SRC:.c=.o)

MSG			=	@/bin/echo -e	\
				"[\e[32mPanoramix\e[39m] Compiled '$(NAME)' lib succesfully"

all:		$(NAME)
			$(MSG)

$(NAME):	$(OBJ)
			ar rc $(LIB_NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:
			$(RM) $(LIB_NAME)

re:			fclean all

.PHONY:		all clean fclean re
