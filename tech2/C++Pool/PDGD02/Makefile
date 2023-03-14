##
## EPITECH PROJECT, 2021
## Project
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	doop

CC			=	gcc

RM			=	rm -f

SRC			=	$(wildcard src/*.c)

OBJ			=	$(SRC:.c=.o)

INC			=	#-I./includes/

LIB			=	#-L./lib/ -lmy # -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

CFLAGS		=	-g0 -O3 -W -Wall -Wextra

DEBUG		=	@echo "[\e[32mDEBUG MODE\e[39m]"

NORMAL		=	@echo "[\e[31mNORMAL MODE\e[39m]"

debug:			CFLAGS = -g3 -O0 -W -Wall -Wextra -Werror -Wno-unused

.c.o:
				$(CC) $(CFLAGS) -c $< -o $@ # $(INC)

all:			$(NAME)
				$(NORMAL)

$(NAME):		$(OBJ)
				# make all -C ./lib/
				$(CC) -o $(NAME) $(CFLAGS) $(OBJ) # $(LIB)

debug:			fclean $(NAME)
				$(DEBUG)

clean:
				$(RM) $(OBJ)
				# make clean  -C ./lib/

clear:
				clear

fclean:			clean
				$(RM) $(NAME)
				# make fclean -C ./lib/

re:				fclean all

.PHONY:			all clean fclean re debug clear
