##
## EPITECH PROJECT, 2021
## my_rpg
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	my_rpg

CC			=	gcc

RM			=	rm -f

SRC			=	$(wildcard src/*.c)								\
				$(wildcard src/init/*.c)						\
				$(wildcard src/init/add/*.c)					\
				$(wildcard src/init/create/*.c)					\
				$(wildcard src/destroy/*.c)						\
				$(wildcard src/render/game/*.c)					\
				$(wildcard src/render/game/game_elements/*.c)	\
				$(wildcard src/render/menu/*.c)					\
				$(wildcard src/utils/*.c)						\
				$(wildcard src/utils/menu/*.c)					\
				$(wildcard src/windows/*.c)						\
				$(wildcard src/windows/menu/*.c)				\
				$(wildcard src/windows/menu/menu_menus/*.c)		\
				$(wildcard src/windows/other/*.c)				\
				$(wildcard src/windows/settings/*.c)			\
				$(wildcard src/windows/game/*.c)				\
				$(wildcard src/windows/game/game_menus/*.c)		\

OBJ			=	$(SRC:.c=.o)

INC			=	-I./includes/

LIB			=	-L./lib/ -lmy -lqueue -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

CFLAGS		=	-g0 -O3 -W -Wall -Wextra -Werror -Wno-unused

DEBUG		=	@echo "[\e[32mDEBUG MODE\e[39m]"

NORMAL		=	@echo "[\e[31mNORMAL MODE\e[39m]"

debug:			CFLAGS = -g3 -O0 -W -Wall -Wextra -Werror -Wno-unused

.c.o:
				$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:			$(NAME)
				$(NORMAL)

$(NAME):		clear $(OBJ)
				make all -C ./lib/
				$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB)

debug:			fclean $(NAME)
				$(DEBUG)

clean:
				$(RM) $(OBJ)
				make clean -C ./lib/

clear:
				clear

fclean:			clean
				$(RM) $(NAME)
				make fclean -C ./lib/

re:				fclean all
				make re -C ./lib/

d_run:			debug
				valgrind ./$(NAME)

run:			re
				./$(NAME)

.PHONY:			all clean fclean re run debug
