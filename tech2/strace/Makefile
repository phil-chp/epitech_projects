##
## EPITECH PROJECT, 2021
## Project
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	strace

CC			=	gcc

RM			=	rm -f

SRC			=	$(wildcard src/*.c)

OBJ			=	$(SRC:.c=.o)

INC			=	-I./includes/

LIB			=	-L./lib/ -lmy

CFLAGS		=	-g0 -O3 -W -Wall -Wextra -Wno-missing-braces -Wno-unused-variable

DEBUG		=	@echo "[\e[31mstrace\e[39m] Debug mode enabled"

NORMAL		=	@echo "[\e[32mstrace\e[39m] Compiled successfully"

debug:			CFLAGS = -g3 -O0 -W -Wall -Wextra -Werror -Wno-unused -Wno-missing-braces

.c.o:
				$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all:			$(NAME)
				$(NORMAL)

$(NAME):		$(OBJ)
				make all -C ./lib/
				$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB)

debug:			fclean $(NAME)
				$(DEBUG)
				$(NORMAL)

clean:
				$(RM) $(OBJ)
				make clean  -C ./lib/

clear:
				clear

fclean:			clean
				$(RM) $(NAME)
				make fclean -C ./lib/

re:				fclean all

.PHONY:			all clean fclean re debug clear
