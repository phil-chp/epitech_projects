##
## EPITECH PROJECT, 2021
## n4s
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	ai

CC			=	gcc

RM			=	rm -f

SRC			=	$(wildcard src/*.c)			\
				$(wildcard src/utils/*.c)	\
				$(wildcard src/destroy/*.c)	\

OBJ			=	$(SRC:.c=.o)

INC			=	-Iincludes

LIB			=	-Llib -lmy

CFLAGS		=	-g0 -O3 -W -Wall -Wextra # -Werror -Wno-unused -Wno-implicit-fallthrough

DEBUG		=	@echo "[\e[1;5;32mDEBUG_MODE\e[0;39m]"

NORMAL		=	@echo "[\e[1;5;34mNORMAL_MODE\e[0;39m]"

ERROR		=	echo "[\e[1;5;31m$$e\e[0;39m]"

.c.o:
				$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all:			$(NAME)
				$(NORMAL)

$(NAME):		clear $(OBJ)
				make all -Clib
				$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB)

clear:
				clear

clean:
				$(RM) $(OBJ)
				make clean  -Clib

fclean:			clean
				$(RM) $(NAME)
				make fclean -Clib

re:				fclean all

run:			re
				./pipes.sh ; e=$$? ; (( $$e != 0 )) && $(ERROR) || echo -n

debug:			CFLAGS = -g3 -O0 -W -Wall -Wextra -Werror -Wno-unused -Wno-implicit-fallthrough

debug:			$(NAME)
				$(DEBUG)

.PHONY:			all clear clean fclean re run debug d_re d_run
