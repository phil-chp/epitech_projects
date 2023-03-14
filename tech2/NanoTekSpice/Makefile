##
## EPITECH PROJECT, 2021
## Epidash
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	nanotekspice

CXX			=	g++

RM			=	rm -f

SRC			=	$(wildcard src/*.cpp)				\
				$(wildcard src/Components/*.cpp)	\

OBJ			=	$(SRC:.cpp=.o)

INC			=	-I./src/

CXXFLAGS	=	-g0 -O3 -W -Wall -Wextra

DEBUG		=	@echo "[\e[32mDEBUG MODE\e[39m]"

NORMAL		=	@echo "[\e[31mNORMAL MODE\e[39m]"

debug:			CXXFLAGS = -g3 -O0 -W -Wall -Wextra -Werror -Wno-unused

# tests:			SRC += $(wildcard tests/*.cpp)
# 				INC += -I./tests/
# 				LIB += -lcriterion
# 				# CXXFLAGS += --verbose

.cpp.o:
				$(CC) $(CXXFLAGS) -c $< -o $@ $(INC)

all:			$(NAME)
				$(NORMAL)

$(NAME):		$(OBJ)
				$(CXX) -o $(NAME) $(OBJ)

debug:			fclean $(NAME)
				$(DEBUG)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re debug
