##
## EPITECH PROJECT, 2021
## Project
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	a.out

CC			=	gcc

RM			=	rm -f

SRC			=	$(wildcard *.c)

OBJ			=	$(SRC:.c=.o)

INC			=	-I./includes/

LIB			=	-L./lib/ -lmy

CFLAGS		=	-g0 -O3 -std=gnu17 -W -Wall -Wextra

DEBUG		=	@echo "[\e[32mDEBUG MODE\e[39m]"

NORMAL		=	@echo "[\e[31mNORMAL MODE\e[39m]"

debug:			CFLAGS = -g3 -O0 -std=gnu17 -W -Wall -Wextra -Werror -Wno-unused

.c.o:
				$(CC) $(CFLAGS) -c $< -o $@ # $(INC)

all:			$(NAME)
				$(NORMAL)

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(CFLAGS) $(OBJ) # $(LIB)

debug:			fclean $(NAME)
				$(DEBUG)

clean:
				$(RM) $(OBJ)

clear:
				clear

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re debug clear
