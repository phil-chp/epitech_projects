##
## EPITECH PROJECT, 2021
## fractals
## File description:
## Makefile
##

NAME	=	fractals

CC		=	gcc

RM		=	rm -f

CP	=	cp -f

HEADERS	=	$(wildcard src/includes/*.h)

SRC		=	$(wildcard src/*.c)

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-I./src/includes/ -L./lib/ -lmy

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
