##
## EPITECH PROJECT, 2022
## Project
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	panoramix

CC			=	gcc

RM			=	rm -f

SRC			=	$(wildcard src/*.c)				\
				$(wildcard src/general/*.c)		\
				$(wildcard src/npcs/*.c)		\
				$(wildcard src/utils/*.c)

OBJ			=	$(SRC:.c=.o)

INC			=	-I./includes/

LIB			=	-L./lib/ -lmy -lpthread

CFLAGS		=	-g0 -O3 -W -Wall -Wextra -pthread

DEBUG		=	@/bin/echo -e "[\e[32mPanoramix\e[39m] Enabled debug mode"

NORMAL		=	@/bin/echo -e "[\e[31mPanoramix\e[39m] Compiled succesfully"

debug:			CFLAGS = -g3 -O0 -W -Wall -Wextra -Werror -Wno-unused

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
