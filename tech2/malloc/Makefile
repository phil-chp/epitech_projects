##
## EPITECH PROJECT, 2022
## MyMalloc (Workspace)
## File description:
## Makefile
##

MAKEFLAGS	=	-s

CC			=	gcc

NAME		=	libmy_malloc.so

BIN_NAME	=	my_malloc

RM			=	rm -f

SRC			=	$(wildcard src/*.c)

BIN_SRC		=	main.c			\
				src/my_lib.c

CFLAGS		=	-W -Wextra -Wall -fPIC

INC			=	-I./includes

OBJ			=	$(SRC:.c=.o)

BIN_OBJ		=	$(BIN_SRC:.c=.o)

BUILD_LIB	=	@echo "[LIB] \e[32mBUILD SUCCESFULL\e[39m"

BUILD_BIN	=	@echo "[BIN] \e[33mBUILD SUCCESFULL\e[39m"

.c.o:
				$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all:			$(NAME)
				$(BUILD_LIB)

bin:			all $(BIN_NAME)
				$(BUILD_BIN)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) -shared -o $(NAME) $(OBJ)

$(BIN_NAME):	$(BIN_OBJ)
				$(CC) -W -Wextra -Wall $(BIN_OBJ)

clean:
				$(RM) $(OBJ)
				$(RM) $(BIN_OBJ)

fclean:			clean
				$(RM) $(NAME)
				$(RM) a.out

re:				fclean all

.PHONY:			all bin clean fclean re
