##
## EPITECH PROJECT, 2022
## Project
## File description:
## Makefile Lib
##

NAME		=	delf

LIB_NAME	=	lib$(NAME).a

RM			=	rm -f

SRC			=	$(wildcard *.c)

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-g0 -O3 -W -Wall -Wextra

INC			=	-I../../includes/

MSG			=	@/bin/echo -e "[\e[32m$(NAME) - Lib\e[39m] Compiled '$(NAME)' lib succesfully"

INFO_MSG	=	@/bin/echo -e "\n\t\e[1;30mThank you for trusting our own personal wrap" \
				"\n\t over \e[1;31mlibelf\e[1;30m! \e[1;32mdelf\e[1;30m (A.K.A. \e[1;32mdickelf\e[1;30m) will not"	 \
				"\n\t    dissapoint, unlike \e[1;31mgelf\e[1;30m. Great coding!\e[0m\n"

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all:		$(NAME)
			$(MSG)
			$(INFO_MSG)

$(NAME):	$(OBJ)
			ar rc ../$(LIB_NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:
			$(RM) ../$(LIB_NAME)

re:			fclean all

.PHONY:		all clean fclean re
