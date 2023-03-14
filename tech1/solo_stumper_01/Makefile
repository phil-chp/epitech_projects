##
## EPITECH PROJECT, 2021
## clean_str
## File description:
## Main Makefile
##

NAME	=	clean_str

CC		=	gcc

RM		=	rm -f

CP		=	cp -f

SRC		=	src/main.c			\
			src/my_formatter.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-L./lib/ -lmy -I./includes/

DFLAGS  +=  -W -Wall -Wextra -g3                   # TO REMOVE

all:		$(NAME)

$(NAME):	$(OBJ)
			make all -C ./lib/
			$(CP) src/includes/*.h includes/
			$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(DFLAGS)

clean:
			$(RM) $(OBJ)
			make clean -C ./lib/
			$(RM) includes/*.h
			# $(RM) *.vgcore
			# $(RM) **/*.gcno
			# $(RM) **/*.gcda
			# $(RM) *.htm

fclean:		clean
			$(RM) $(NAME)
			make fclean -C ./lib/

re:			fclean all
			make re -C ./lib/

.PHONY:		all clean fclean re
