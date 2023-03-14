##
## EPITECH PROJECT, 2020
## my_radar
## File description:
## Makefile
##

NAME	=	my_radar

CC		=	gcc

CP		=	cp -f

RM		=	rm -f

SRC		=	src/main.c								\
			src/get_positions.c						\
			src/element_handler/create_elements.c	\
			src/element_handler/check_collision.c	\
			src/element_handler/orientation.c		\
			src/element_handler/move_planes.c		\
			src/var_handler/framebuffer_create.c	\
			src/var_handler/vars_create.c			\
			src/var_handler/framebuffer_destroy.c	\
			src/var_handler/screen_end.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-I./src/includes/ -L./src/lib/ -lmy

LFLAGS	+=	-lcsfml-graphics -lcsfml-system -lm

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./src/lib/ all
			$(CP) src/includes/*.h includes/
			$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LFLAGS)

clean:
			make -C ./src/lib/ clean
			$(RM) $(OBJ)

fclean:		clean
			make -C ./src/lib/ fclean
			$(RM) $(NAME)
			$(RM) includes/*.h

re:			fclean all
			make -C ./src/lib/ re

.PHONY:		all clean fclean re
