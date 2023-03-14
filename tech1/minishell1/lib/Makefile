##
## EPITECH PROJECT, 2020
## Navy
## File description:
## lib makefile
##

NAME	=	libmy.a

SRC		=	my/my_putchar.c				\
			my/my_putnbr.c				\
			my/my_putstr.c				\
			my/my_strlen.c				\
			my/my_strdup.c				\
			my/my_put_tbl.c				\
			my/my_strcmp.c				\
			my/my_strcat.c				\
			my/my_getenv.c				\
			my/my_strupcase.c			\
			my/my_str_to_word_array.c	\
			my/my_lprintf.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			rm -f my/$(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
