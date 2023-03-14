##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## d10
##

SRC	=	my_putchar.c			\
		my_strstr.c			\
		my_isneg.c			\
		my_strcmp.c			\
		my_put_nbr.c			\
		my_strncmp.c			\
		my_swap.c			\
		my_strupcase.c			\
		my_putstr.c			\
		my_strlowcase.c			\
		my_strlen.c			\
		my_strcapitalize.c		\
		my_getnbr.c			\
		my_str_isalpha.c		\
		my_sort_int_array.c		\
		my_str_isnum.c			\
		my_compute_power_rec.c		\
		my_str_islower.c		\
		my_compute_square_root.c	\
		my_str_isupper.c		\
		my_is_prime.c			\
		my_str_isprintable.c		\
		my_find_prime_sup.c		\
		my_showstr.c			\
		my_strcpy.c			\
		my_showmem.c			\
		my_strncpy.c			\
		my_strcat.c			\
		my_revstr.c			\
		my_str_to_word_array.c		\
		my_strncat.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

MY	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) *.o
	cp -f $(NAME) ../$(NAME)
	cp -f $(MY) ../../include/$(MY)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/$(MY)

re:	fclean all
