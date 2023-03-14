##
## EPITECH PROJECT, 2021
## minishell1 (Workspace)
## File description:
## Makefile
##

NAME	=	mysh

CC	=	gcc

RM	=	rm -f

CP	=	cp -f

SRC	=	src/main.c							\
		src/start_end/term_getline.c		\
		src/start_end/build_commands.c		\
		src/start_end/free_handling.c		\
		src/handle_params/command_handler.c	\
		src/handle_params/handle_env.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-L./lib/ -lmy -I./include/

all:		$(NAME)

$(NAME):	$(OBJ)
			make all -C ./lib/
			$(CP) src/includes/*.h includes/
			$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(DFLAGS)

clean:
			$(RM) $(OBJ)
			make clean -C ./lib/

fclean:		clean
			$(RM) $(NAME)
			$(RM) includes/*.h
			make fclean -C ./lib/

re:			fclean all
			make re -C ./lib/

.PHONY:		all clean fclean re
