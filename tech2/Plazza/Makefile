##
## EPITECH PROJECT, 2021
## Epidash
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	plazza

CXX			=	g++

RM			=	rm -f

SRC			=	$(wildcard src/*.cpp)			\
				$(wildcard src/Com/*.cpp)		\
				$(wildcard src/Errors/*.cpp)	\
				$(wildcard src/Kitchen/*.cpp)	\
				$(wildcard src/Menu/*.cpp)		\
				$(wildcard src/NamedPipe/*.cpp)	\
				$(wildcard src/Plazza/*.cpp)	\
				$(wildcard src/Reception/*.cpp)	\
				$(wildcard src/Utils/*.cpp)		\
				# $(wildcard src/Mutex/*.cpp)		\
				# $(wildcard src/Kitchen/Cook/*.cpp)	\

OBJ			=	$(SRC:.cpp=.o)

INC			=	-I./src/


LIB			=	-L./lib/ -lmy

CXXFLAGS	=	-g0 -O3 -W -Wall -Wextra

DEBUG		=	@/bin/echo -e "[\e[32m$(NAME)\e[39m] Enabled debug mode"

NORMAL		=	@/bin/echo -e "[\e[31m$(NAME)\e[39m] Compiled succesfully"

debug:		CXXFLAGS = -g3 -O0 -W -Wall -Wextra -Werror -Wno-unused

.cpp.o:
			$(CC) $(CXXFLAGS) -c $< -o $@ $(INC)

all:		$(NAME)
			$(NORMAL)

$(NAME):	$(OBJ)
			$(CXX) -o $(NAME) $(OBJ)

debug:		fclean $(NAME)
			$(DEBUG)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re debug
