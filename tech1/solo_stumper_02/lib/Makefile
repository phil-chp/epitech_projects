##
## EPITECH PROJECT, 2021
## solostumper02
## File description:
## Lib Makefile
##

NAME	=	libmy.a

RM	=	rm -f

SRC	=	my/my_strlen.c		\
		my/my_putchar.c		\
		my/my_putstr.c		\
		my/my_strlowcase.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
