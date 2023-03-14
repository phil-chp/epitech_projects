##
## EPITECH PROJECT, 2021
## duostumper2
## File description:
## Makefile
##

NAME	=	gameoflife

CC	=	@gcc

RM	=	@rm -f

CP	=	@cp -f

HEADERS	=	$(wildcard src/includes/*.h)

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-L./lib/ -lmy -I./src/includes/

DFLAGS	+=	-O3 -W -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		make all -C ./lib/
		$(CP) $(HEADERS) includes/
		$(CC) -o $@ $(SRC) $(DFLAGS) $(CFLAGS)

clean:
		$(RM) $(OBJ)
		make clean -C ./lib/
		$(RM) $(wildcard includes/*.h)

fclean:		clean
		$(RM) $(NAME)
		make fclean -C ./lib/

re:		fclean all
		make re -C ./lib/

.PHONY:		all clean fclean re
