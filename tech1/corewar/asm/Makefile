##
## EPITECH PROJECT, 2021
## corewar
## File description:
## asm
##

NAME		=	asm

CC			=	gcc

RM			=	rm -f

SRC			=	src/get_command.c						\
				src/get_name_and_comment.c				\
				src/main.c								\
				src/read_and_check.c					\
				src/print_usage.c						\
				../include/op.c							\
				../corewar/src/utils/my_swap_endian.c

OBJ			=	$(SRC:.c=.o)

INC			=	-I../include/

LIB			=	-L../lib/ -lmy

CFLAGS		=	-W -Wall -Wextra

.c.o:
				$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all:			$(NAME)
				$(NORMAL)

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
