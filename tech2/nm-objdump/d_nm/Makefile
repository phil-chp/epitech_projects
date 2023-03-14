##
## EPITECH PROJECT, 2022
## Project
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	my_nm

CC			=	gcc

RM			=	rm -f

SRC			=	$(wildcard src/*.c)			\
				$(wildcard src/arch32/*.c)	\
				$(wildcard src/arch64/*.c)	\
				$(wildcard ../src/*.c)

OBJ			=	$(SRC:.c=.o)

INC			=	-I../includes/

CFLAGS		=	-g0 -O3 -W -Wall -Wextra -Wno-unused -Wno-unused-result

MSG			=	@echo "[\e[32mnm\e[39m] Compiled succesfully"

DEBUG		=	@echo "[\e[33mnm\e[39m] Debug mode enabled"

debug:			CFLAGS = -g3 -O0 -W -Wall -Wextra -Werror -Wno-unused -Wno-unused-result

.c.o:
				$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all:			$(NAME)
				$(MSG)

$(NAME):		$(OBJ)
				$(CC) -o ../$(NAME) $(OBJ)

debug:			fclean $(NAME)
				$(DEBUG)
				$(MSG)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) ../$(NAME)

re:				fclean all

.PHONY:			all clean fclean re debug
