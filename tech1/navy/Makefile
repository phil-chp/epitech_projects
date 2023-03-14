##
## EPITECH PROJECT, 2020
## navy
## File description:
## Makefile
##

NAME	=	navy

CC		=	gcc

RM		=	rm -f

CP		=	cp -f

SRC		=	src/main.c 							\
			src/plays.c							\
			src/users.c							\
			src/map_manage_signal.c				\
			src/text_handling/my_handlers.c		\
			src/text_handling/term_getline.c	\
			src/text_handling/use_files.c		\
			src/map_build/aread.c				\
			src/map_build/deterline.c			\
			src/map_build/init_plan.c			\
			src/map_build/map_maker.c			\
			src/map_build/map_parser.c			\
			src/map_build/set_array.c			\
			src/check_signal.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-I./include/ -L./lib/ -lmy -W -Wall -Wextra -g3

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./lib/ all
			$(CP) src/*.h includes/
			$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
			$(RM) $(OBJ)
			make -C ./lib/ clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) includes/*.h
			make -C ./lib/ fclean

re:			fclean all
			make -C ./lib/ re

.PHONY:		all clean fclean re
