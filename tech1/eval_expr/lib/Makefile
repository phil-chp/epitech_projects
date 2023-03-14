##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## bistro
##

SRC	=	my/my_putchar.c			\
		my/my_strstr.c			\
		my/my_isneg.c			\
		my/my_strcmp.c			\
		my/my_put_nbr.c			\
		my/my_strncmp.c			\
		my/my_swap.c			\
		my/my_strupcase.c		\
		my/my_putstr.c			\
		my/my_strlowcase.c		\
		my/my_strlen.c			\
		my/my_strcapitalize.c		\
		my/my_getnbr.c			\
		my/my_str_isalpha.c		\
		my/my_sort_int_array.c		\
		my/my_str_isnum.c		\
		my/my_compute_power_rec.c	\
		my/my_str_islower.c		\
		my/my_compute_square_root.c	\
		my/my_str_isupper.c		\
		my/my_is_prime.c		\
		my/my_str_isprintable.c		\
		my/my_find_prime_sup.c		\
		my/my_showstr.c			\
		my/my_strcpy.c			\
		my/my_showmem.c			\
		my/my_strncpy.c			\
		my/my_strcat.c			\
		my/my_revstr.c			\
		my/my_strdup.c			\
		my/my_str_to_word_array.c	\
		my/my_strncat.c			\
		my/my_atoi.c			\
		pers/retiringzero.c		\
		pers/change_tcrush.c		\
		pers/is_base.c			\
		pers/is_ops.c			\
		pers/add_res_multi.c		\
		pers/change_t.c			\
		pers/check_error.c		\
		pers/check_minus.c		\
		pers/checkmyarg.c		\
		pers/checkprim.c		\
		pers/checksec.c			\
		pers/checksize.c		\
		pers/checkzero.c		\
		pers/close_parent.c		\
		pers/compare.c			\
		pers/det1.c			\
		pers/det2.c			\
		pers/det3.c			\
		pers/det4.c			\
		pers/deter_quot.c		\
		pers/firstzero.c		\
		pers/growstr.c			\
		pers/minus_n_minus.c		\
		pers/minus_n_plus.c		\
		pers/minus_remover.c		\
		pers/mult_res_mult.c		\
		pers/my_swap_str.c		\
		pers/new_eval.c			\
		pers/onlynumb.c			\
		pers/open_parent.c		\
		pers/plus_n_minus.c		\
		pers/plus_n_plus.c		\
		pers/prep.c			\
		pers/putminus.c			\
		pers/retarg.c			\
		pers/retirezero.c		\
		pers/section_add.c		\
		pers/secure_zero.c		\
		pers/set_calc.c			\
		pers/setminus.c			\
		pers/table.c			\
		pers/make_table.c		\
		pers/targetstr.c		\
		pers/calcprim.c			\
		pers/calcprim_parent.c		\
		pers/calcsec.c			\
		pers/calcsec_parent.c		\
		pers/first_module.c		\
		pers/module.c			\
		pers/second_module.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

MY	=	../include/

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
