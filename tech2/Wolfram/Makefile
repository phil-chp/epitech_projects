##
## EPITECH PROJECT, 2021
## Project
## File description:
## Makefile
##

MAKEFLAGS	=	-s

STACK		=	stack
CP			=	cp -f
RM			=	rm -f

PROJ_NAME	=	Wolfram
BIN_NAME	=	wolfram
HSFLAGS		=	 --verbosity warn
BIN_PATH	=	$(shell stack path --local-install-root)/bin/$(PROJ_NAME)-exe

MSG			=	@echo "[\e[32mWolfram\e[39m] Build sucessful"
DEBUG_MSG	=	@echo "[\e[31mWolfram\e[39m] Debug mode enabled"

debug:			HSFLAGS	= --verbosity error

all:
				$(STACK) build $(HSFLAGS)
				$(CP) $(BIN_PATH) $(BIN_NAME)
				$(MSG)

clean:
				$(STACK) clean

fclean:			clean
				$(RM) $(BIN_NAME)

debug:			all
				$(DEBUG_MSG)

re:				fclean all

.PHONY:			all clean fclean re debug
