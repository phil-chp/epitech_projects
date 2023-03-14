##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## infin add
##

SRC	=	lib/my/my_putchar.c			\
		lib/my/my_strstr.c			\
		lib/my/my_isneg.c			\
		lib/my/my_strcmp.c			\
		lib/my/my_put_nbr.c			\
		lib/my/my_strncmp.c			\
		lib/my/my_swap.c			\
		lib/my/my_strupcase.c			\
		lib/my/my_putstr.c			\
		lib/my/my_strlowcase.c			\
		lib/my/my_strlen.c			\
		lib/my/my_strcapitalize.c		\
		lib/my/my_getnbr.c			\
		lib/my/my_str_isalpha.c			\
		lib/my/my_sort_int_array.c		\
		lib/my/my_str_isnum.c			\
		lib/my/my_compute_power_rec.c		\
		lib/my/my_str_islower.c			\
		lib/my/my_compute_square_root.c		\
		lib/my/my_str_isupper.c			\
		lib/my/my_is_prime.c			\
		lib/my/my_str_isprintable.c		\
		lib/my/my_find_prime_sup.c		\
		lib/my/my_showstr.c			\
		lib/my/my_strcpy.c			\
		lib/my/my_showmem.c			\
		lib/my/my_strncpy.c			\
		lib/my/my_strcat.c			\
		lib/my/my_revstr.c			\
		lib/my/my_str_to_word_array.c		\
		lib/my/my_strncat.c

ADD	=	infin_add.c		\
		infin_function.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

MY	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc lib/my/$(NAME) $(OBJ)
	cp -f lib/my/$(NAME) lib/$(NAME)
	cp -f lib/my/$(MY) include/$(MY)
	gcc -o infin_add $(ADD) -I./include/ -L./lib/ -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f lib/$(NAME)
	rm -f lib/my/$(NAME)
	rm -f include/$(MY)
	rm -f infin_add

re:	fclean all
