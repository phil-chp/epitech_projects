##
## EPITECH PROJECT, 2022
## Project
## File description:
## Makefile
##

MAKEFLAGS	=	-s

all:			nm objdump

nm:
				make all -C ./d_nm/

objdump:
				make all -C ./d_objdump/

debug:
				make debug -C ./d_nm/
				# make debug -C ./d_objdump/

clean:
				make clean -C ./d_nm/
				# make clean -C ./d_objdump/

fclean:			clean
				make fclean -C ./d_nm/
				# make fclean -C ./d_objdump/

re:				fclean all

.PHONY:			all clean fclean re debug
