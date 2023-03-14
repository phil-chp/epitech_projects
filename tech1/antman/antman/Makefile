##
## EPITECH PROJECT, 2020
## Antman
## File description:
## Antman - Makefile
##

NAME	=	antman

CC		=	gcc

RM		=	rm -f

SRC		=	src/main.c							\
			src/antman_manager.c				\
			src/create_compressed.c				\
			../src/check_word.c					\
			../src/free_content.c				\
			../src/parse_word.c					\
			../src/initialisation/init_buff.c	\
			../src/initialisation/read_file.c	\
			../src/bubble_sort_array.c			\
			../src/str_edition/add_new_word.c	\
			../src/str_edition/add_plus_one.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-L../lib/ -llprintf -I./include/

DFLAGS  +=  -W -Wall -Wextra -g3                   # TO REMOVE

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(DFLAGS)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
