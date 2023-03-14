##
## EPITECH PROJECT, 2022
## Groundhog (Workspace)
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	groundhog

RM			=	rm -f

NORMAL		=	@/bin/echo -e "[\e[31mGroundhog\e[39m] Compiled succesfully"

all:
			cp ./src/$(NAME)_.py $(NAME)
			chmod +x groundhog
			$(NORMAL)

bonus:		fclean
			cp ./bonus/$(NAME).py $(NAME)
			chmod +x groundhog
			$(NORMAL)

clean:

fclean:
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re debug clear
