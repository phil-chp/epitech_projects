##
## EPITECH PROJECT, 2021
## Project Name
## File description:
## Makefile
##

NAME		=	corewar

CC			=	gcc

RM			=	rm -f

SRC			=	src/main.c									\
				../include/op.c								\
				src/init/init_champs.c						\
				src/init/fill_arena.c						\
				src/init/init_alive_list.c					\
				src/init/init_fork.c						\
				src/destroy/destroy_code_byte_elements.c	\
				src/destroy/destroy_arena.c					\
				src/utils/check_dot_cor.c					\
				src/utils/get_code_from_code_bytes.c		\
				src/utils/corewar_loop_utils.c				\
				src/utils/corewar_loop_prints.c				\
				src/utils/hex_to_deci.c						\
				src/utils/my_op_code_converter.c			\
				src/utils/my_str_to_hex.c					\
				src/utils/my_swap_endian.c					\
				src/instructions/f_add.c					\
				src/instructions/f_aff.c					\
				src/instructions/f_and.c					\
				src/instructions/f_fork.c					\
				src/instructions/f_ld.c						\
				src/instructions/f_ldi.c					\
				src/instructions/f_lfork.c					\
				src/instructions/f_live.c					\
				src/instructions/f_lld.c					\
				src/instructions/f_lldi.c					\
				src/instructions/f_or.c						\
				src/instructions/f_st.c						\
				src/instructions/f_sti.c					\
				src/instructions/f_sub.c					\
				src/instructions/f_xor.c					\
				src/instructions/f_zjmp.c					\
				# ooga/booga/wildcard/go/brrrrrrrr.c
################################################################################
#    This is so stupid, a year of work just to go back to sticks and stones    #
#                            Fix your jenkins, ffs                             #
################################################################################

OBJ			=	$(SRC:.c=.o)

INC			=	-I../include/

LIB			=	-L../lib/ -lmy -lm

CFLAGS		=	-W -Wall -Wextra

.c.o:
				$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all:			$(NAME)

$(NAME):		$(OBJ)
				make all -C ../lib/
				$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB)

clean:
				$(RM) $(OBJ)
				make clean  -C ../lib/

fclean:			clean
				$(RM) $(NAME)
				make fclean -C ../lib/

re:				fclean all

.PHONY:			all clean fclean re
