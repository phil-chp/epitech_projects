##
## EPITECH PROJECT, 2021
## Project
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	pushswap_checker

CC			=	ghc

RM			=	rm -f

SRC			=	$(shell find src -name '*.hs' -o -name '*.lhs')

CFLAGS		=	--make -O3

DEBUG		=	@echo "[\e[31mCOMPILED SUCCESFULLY IN DEBUG MODE\e[39m]"

NORMAL		=	@echo "[\e[32mCOMPILED SUCCESFULLY\e[39m]"

debug:			CFLAGS = -O0

# i:				CFLAGS = --interactive -O0

all:			$(NAME)
				$(NORMAL)

$(NAME):
				$(CC) $(SRC) $(CFLAGS) -o $(NAME)

debug:			fclean $(NAME)
				$(DEBUG)

clean:
				$(RM) $(shell find . -name '*.hi' -o -name '*.o')

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re debug
