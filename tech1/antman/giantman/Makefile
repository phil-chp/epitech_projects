##
## EPITECH PROJECT, 2020
## Antman
## File description:
## Giantman - Makefile
##

NAME	=	giantman

CC		=	gcc

RM		=	rm -f

SRC		=	src/main.c							\
			src/giantman_manager.c				\
			src/create_decompressed.c			\
			../src/free_content.c				\
			../src/parse_word.c					\
			../src/initialisation/init_buff.c	\
			../src/initialisation/read_file.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-L../lib/ -llprintf -I./include/

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
