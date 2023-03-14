##
## EPITECH PROJECT, 2022
## B-AIA-500-NCE-5-1-gomoku-philippe.cheype [WSL : Ubuntu]
## File description:
## Makefile
##


MAKEFLAGS	=	-s

CP			=	cp -f

NAME		=	pbrain-gomoku-ai

COMPILE		=	$(shell cp $(NAME).py $(NAME))
COMPILE_EXE	=	$(shell PYTHONOPTIMIZE=3 && python3 -m PyInstaller $(NAME).py --log-level WARN)

CHMOD		=	$(shell chmod +x $(NAME))

COMPILED	=	@/bin/echo -e "[\e[31mGomoku\e[39m] Compiled succesfully"

all:
			$(COMPILE)
			$(CHMOD)
			$(NORMAL)

exe:
			$(COMPILE_EXE)
			$(COMPILED)

clean:
			rm -rf *.log
			rm -rf build
			rm -rf dist

fclean:		clean
			rm -rf $(NAME)
			rm -rf $(NAME).spec

re:			fclean all

re_exe:		fclean exe

.PHONY:		all clean fclean re debug clear
