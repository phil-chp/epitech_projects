##
## EPITECH PROJECT, 2020
## Antman
## File description:
## Main Makefile
##

NAME	=	antman

all:
			make all 	-C ./lib/
			make all 	-C ./antman/
			make all 	-C ./giantman/

clean:
			make clean 	-C ./lib/
			make clean 	-C ./antman/
			make clean 	-C ./giantman/

fclean:		clean
			make fclean -C ./lib/
			make fclean -C ./antman/
			make fclean -C ./giantman/

re:			fclean all
			make re 	-C ./lib/
			make re 	-C ./antman/
			make re 	-C ./giantman/

.PHONY:		all clean fclean re
