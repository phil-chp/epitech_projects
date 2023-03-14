##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## bistro
##

SRC	=	my/my_strlen.c				\
		my/my_strcmp.c				\
		my/my_putstr.c				\
		my/my_atoi.c				\
		my/my_revstr.c				\
		my/my_strcat.c				\
		my/my_putchar.c				\
		my/my_strcpy.c 				\
		my/my_strdup.c 				\
		pers/num_count.c			\
		pers/values_check.c			\
		pers/retiringzero.c			\
		pers/change_tcrush.c		\
		pers/is_base.c				\
		pers/is_ops.c				\
		pers/add_res_multi.c		\
		pers/change_t.c				\
		pers/check_error.c			\
		pers/check_minus.c			\
		pers/checkmyarg.c			\
		pers/checkprim.c			\
		pers/checksec.c				\
		pers/checksize.c			\
		pers/checkzero.c			\
		pers/close_parent.c			\
		pers/compare.c				\
		pers/det1.c					\
		pers/det2.c					\
		pers/det3.c					\
		pers/det4.c					\
		pers/deter_quot.c			\
		pers/firstzero.c			\
		pers/growstr.c				\
		pers/minus_n_minus.c		\
		pers/minus_n_plus.c			\
		pers/minus_remover.c		\
		pers/mult_res_mult.c		\
		pers/my_swap_str.c			\
		pers/new_eval.c				\
		pers/onlynumb.c				\
		pers/open_parent.c			\
		pers/plus_n_minus.c			\
		pers/plus_n_plus.c			\
		pers/prep.c					\
		pers/putminus.c				\
		pers/retarg.c				\
		pers/retirezero.c			\
		pers/section_add.c			\
		pers/secure_zero.c			\
		pers/set_calc.c				\
		pers/setminus.c				\
		pers/table.c				\
		pers/make_table.c			\
		pers/targetstr.c			\
		pers/calcprim.c				\
		pers/calcprim_parent.c		\
		pers/calcsec.c				\
		pers/calcsec_parent.c		\
		pers/first_module.c			\
		pers/module.c				\
		pers/second_module.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

MY		=	../include/

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all