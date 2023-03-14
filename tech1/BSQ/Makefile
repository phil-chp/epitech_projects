##
## EPITECH PROJECT, 2020
## File
## File description:
## Main makefile
##

SRC		=	$(wildcard src/*.c)						\
			$(wildcard src/algorithm/*.c)			\
			$(wildcard src/build_terrain/*.c)		\
			$(wildcard src/destroy/*.c)

NAME	=	bsq

LIB		=	/lib/

MY		=	include/

HEADERS	=	$(wildcard src/headers/*.h)

CFLAGS	+=	-I./$(MY) -L.$(LIB) -lmy

TEST	=	unit_tests

all:
			make -C./lib/ all
			cp -f $(HEADERS) $(MY)
			gcc -O3 -o $(NAME) $(SRC) $(CFLAGS)

clean:
			make -C./lib/ clean

fclean:		clean
			rm -f $(NAME)
			rm -f $(MY)*.h
			make -C lib/ fclean

re:			fclean all
			make -C./lib/ re

.PHONY:		all clean fclean re
