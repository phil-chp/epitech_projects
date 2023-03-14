##
## EPITECH PROJECT, 2021
## matchstick
## File description:
## Makefile
##

NAME	=	matchstick

CC		=	gcc

RM		=	rm -f

CP		=	cp -f

DEBUG	=	@echo "[\e[32mDEBUG_MODE\e[39m]"

HEADERS	=	$(wildcard src/includes/*.h)

SRC		=	$(wildcard src/*.c)			\
			$(wildcard src/destroy/*.c)	\
			$(wildcard src/error/*.c)	\
			$(wildcard src/game/*.c)	\
			$(wildcard src/map/*.c)		\
			$(wildcard src/turns/*.c)	\

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-I./src/includes/ -L./lib/ -lmy

DFLAGS	+=	-W -Wall -Wextra

debug:		DFLAGS += -g3

all:		$(NAME)

$(NAME):	$(OBJ)
			make all -C ./lib/
			$(CP) $(HEADERS) includes/
			$(CC) -o $@ $(SRC) $(DFLAGS) $(CFLAGS)

debug:		fclean $(NAME)
			$(DEBUG)

clean:
			$(RM) $(OBJ)
			make clean -C ./lib/
			$(RM) $(wildcard includes/*.h)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C ./lib/

re:			fclean all
			make re -C ./lib/

.PHONY:		all clean fclean re debug
