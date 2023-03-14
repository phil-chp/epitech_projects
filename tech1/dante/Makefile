##
## EPITECH PROJECT, 2021
## dante (Workspace)
## File description:
## Makefile
##

all:
			make all 	-C ./generator/
			make all 	-C ./solver/

debug:		fclean
			make debug 	-C ./generator/
			make debug 	-C ./solver/

clean:
			make clean 	-C ./generator/
			make clean 	-C ./solver/

fclean:		clean
			make fclean -C ./generator/
			make fclean -C ./solver/

re:			fclean all
			make re 	-C ./generator/
			make re 	-C ./solver/

.PHONY:		all clean fclean re debug
