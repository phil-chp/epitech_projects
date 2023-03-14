##
## EPITECH PROJECT, 2021
## temp_dante
## File description:
## solver Makefile
##

NAME	=	solver

CC		=	gcc

RM		=	rm -f

SRC		=	$(wildcard src/*.c)			\
			$(wildcard src/maze/*.c)	\
			$(wildcard src/utils/*.c)

OBJ		=	$(SRC:.c=.o)

INC		=	-I./includes/

LIB		=	-L../lib/ -lstack -lmy

CFLAGS	+=	-O3 -W -Wall -Wextra

DEBUG	=	@echo "[\e[32mDEBUG_MODE\e[39m]"

debug:		CFLAGS += -g3

.c.o:
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			make all    -C ../lib/
			$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB)

debug:		fclean $(NAME)
			$(DEBUG)

clean:
			$(RM) $(OBJ)
			make clean  -C ../lib/

fclean:		clean
			$(RM) $(NAME)
			make fclean -C ../lib/

re:			fclean all
			make re     -C ../lib/

.PHONY:		all clean fclean re debug
