##
## EPITECH PROJECT, 2021
## my_sokoban
## File description:
## Makefile
##

NAME	=	my_sokoban

CC		=	gcc

RM		=	rm -f

CP		=	cp -f

HEADERS	=	$(wildcard src/includes/*.h)

SRC		=	$(wildcard src/*.c)				\
			$(wildcard src/input/*.c)		\
			$(wildcard src/map/*.c)			\
			$(wildcard src/init/*.c)		\
			$(wildcard src/small_size/*.c)

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-lncurses -L./lib/ -lmy -I./src/includes/

DFLAGS	+=	-W -Wall -Wextra -g3

all:		$(NAME)

$(NAME):	$(OBJ)
			make all -C ./lib/
			$(CP) $(HEADERS) includes/
			$(CC) -o $(NAME) $(SRC) $(DFLAGS) $(CFLAGS)

clean:
			$(RM) $(OBJ)
			make clean -C ./lib/
			$(RM) $(wildcard includes/*.h)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C ./lib/

re:			fclean all
			make re -C ./lib/

.PHONY:		all clean fclean re
