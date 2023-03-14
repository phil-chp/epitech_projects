##
## EPITECH PROJECT, 2020
## File
## File description:
## Main makefile
##

SRC		=		sources/my_putchar.c			\
				sources/my_strlen.c				\
				sources/my_putstr.c				\
				sources/my_get_str.c			\
				sources/my_show_oct_str.c		\
				sources/my_int_len.c			\
				sources/my_put_nbr.c			\
				sources/my_getnbr.c				\
				sources/my_put_short_nbr.c		\
				sources/my_put_long_nbr.c		\
				sources/my_put_long_uns_nbr.c	\
				sources/my_put_uns_nbr.c		\
				sources/my_put_oct_nbr.c		\
				sources/my_put_uns_bin_nbr.c	\
				sources/my_put_uns_hex_nbr.c	\
				sources/my_put_uns_hex_nbr_maj.c\
				sources/my_str_isprintable.c	\
				sources/my_char_isprintable.c	\
				sources/my_percent.c			\
				sources/my_nothing.c			\
				sources/my_printf.c				\
				sources/my_put_address.c		\
				sources/indent_param.c			\
				sources/hash.c					\
				sources/space_adder.c			\
				sources/check_plus.c			\
				sources/check_space.c			\
				sources/check_short.c			\
				sources/check_long.c

USRC	=		tests/tests_address.c			\
				tests/tests_bases.c				\
				tests/tests_char.c				\
				tests/tests_int.c				\
				tests/tests_no_params.c			\
				tests/tests_other.c				\
				tests/tests_string.c			\
				tests/tests_uns_hex.c			\
				tests/tests_unsigned.c

OBJ		=		$(SRC:.c=.o)

NAME	=		libmy.a

TEST	=		unit_tests

MY		=		/includes/

CFLAGS	+=		-I.$(MY)

all:	$(NAME)
	ar rc $(NAME) $(OBJ)

$(NAME):		$(OBJ)

clean:
	rm -f $(OBJ)

fclean:			clean
	rm -f $(NAME)

re:				fclean all

unit_tests:		fclean $(NAME)
	ar rc $(NAME) $(OBJ)
	gcc -o $(TEST) $(USRC) -I.$(MY) -L./ -lmy --coverage -lcriterion

run_tests:		unit_tests
	./$(TEST)
