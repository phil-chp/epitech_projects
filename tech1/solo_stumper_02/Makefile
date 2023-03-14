##
## EPITECH PROJECT, 2021
## solostumper02
## File description:
## Main Makefile
##

NAME	=	palindrome

CC	=	gcc

RM	=	rm -f

CP	=	cp -f

SRC	=	src/main.c		\
		src/palindrome.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-L./lib/ -lmy -I./includes/


all:		$(NAME)

$(NAME):	$(OBJ)
		make all -C ./lib/
		$(CP) src/includes/*.h includes/
		$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
		$(RM) $(OBJ)
		make clean -C ./lib/
		$(RM) includes/*.h

fclean:		clean
		$(RM) $(NAME)
		make fclean -C ./lib/

re:		fclean all
		make re -C ./lib/

.PHONY:		all clean fclean re
