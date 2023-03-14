##
## EPITECH PROJECT, 2022
## Project
## File description:
## Makefile Lib
##

NAME		=	stack

LIB_NAME	=	lib$(NAME).a

RM			=	rm -f

SRC			=	$(wildcard *.c)

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-g0 -O3 -W -Wall -Wextra

MSG			=	@/bin/echo -e "[\e[32m$(NAME) - Lib\e[39m] Compiled '$(NAME)' lib succesfully"

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)
			$(MSG)

$(NAME):	$(OBJ)
			ar rc ../$(LIB_NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:
			$(RM) ../$(LIB_NAME)

re:			fclean all

.PHONY:		all clean fclean re
