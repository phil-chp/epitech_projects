##
## EPITECH PROJECT, 2020
## my_ls
## File description:
## Lib Makefile
##

NAME	=	libmy.a

SRC		=	lib/my_putstr.c			\
			lib/my_strlen.c			\
			lib/my_putchar.c		\
			lib/my_putnbr.c			\
			lib/my_strcat.c			\
			lib/my_strcpy.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra

.PHONY:		all
all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

.PHONY:		clean
clean:
			rm -f $(OBJ)

.PHONY:		fclean
fclean:		clean
			rm -f $(NAME)

.PHONY:		re
re:			fclean all
