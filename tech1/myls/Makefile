##
## EPITECH PROJECT, 2020
## my_ls
## File description:
## Main Makefile
##

NAME	=	my_ls

SRC		=	main.c					\
			src/my_ls.c				\
			src/calculate_total.c	\
			src/file_type.c			\
			src/file_perms.c		\
			src/file_hard_link.c	\
			src/file_uid.c			\
			src/file_gid.c			\
			src/file_size.c			\
			src/file_minor.c		\
			src/file_major.c		\
			src/file_date_time.c

CFLAGS	+=	-L./src/ -lmy -I./include/ -W -Wall -Wextra -g3	 #REM

.PHONY:		all
all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./src/ all
			gcc -o $(NAME) $(SRC) $(CFLAGS)

.PHONY:		clean
clean:
			rm -f $(OBJ)
			make -C ./src/ clean
			rm -f *.vgcore
			rm -f *.gcno
			rm -f *.gcda

.PHONY:		fclean
fclean:		clean
			rm -f $(NAME)
			make -C ./src/ fclean

.PHONY:		re
re:			fclean all
			make -C ./src/ re
