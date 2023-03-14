##
## EPITECH PROJECT, 2022
## Project
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	ftrace

CC			=	gcc

RM			=	rm -f

SRC			=	$(wildcard src/*.c)

OBJ			=	$(SRC:.c=.o)

INC			=	-I./includes/

LIB			=	-L./lib/ -ldelf -lelf -lstack

CFLAGS		=	-g0 -O3 -W -Wall -Wextra

DEBUG		=	@/bin/echo -e "[\e[32m$(NAME)\e[39m] Enabled debug mode"

NORMAL		=	@/bin/echo -e "[\e[31m$(NAME)\e[39m] Compiled succesfully"

debug:			CFLAGS = -g3 -O0 -W -Wall -Wextra -Werror -Wno-unused

.c.o:
				$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all:			$(NAME)
				$(NORMAL)

$(NAME):		$(OBJ)
				make all -C ./lib/delf/
				make all -C ./lib/stack/
				$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB)

debug:			fclean $(NAME)
				$(DEBUG)

clean:
				$(RM) $(OBJ)
				make clean -C ./lib/delf/
				make clean -C ./lib/stack/

clear:
				clear

fclean:			clean
				$(RM) $(NAME)
				make fclean -C ./lib/delf/
				make fclean -C ./lib/stack/

re:				fclean all

.PHONY:			all clean fclean re debug clear
