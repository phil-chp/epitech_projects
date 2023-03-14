##
## EPITECH PROJECT, 2021
## Epidash
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	my_convert_temp

CXX			=	g++

RM			=	rm -f

SRC			=	$(wildcard *.cpp)

OBJ			=	$(SRC:.cpp=.o)

INC			=	-I./includes/

CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror

DEBUG		=	@echo "[\e[32mDEBUG MODE\e[39m]"

NORMAL		=	@echo "[\e[31mNORMAL MODE\e[39m]"

debug:			CXXFLAGS = -g3 -std=c++20 -W -Wall -Wextra -Werror -Wno-unused

tests:			SRC += $(wildcard tests/*.cpp)
				INC += -I./tests/
				LIB += -lcriterion
				# CXXFLAGS += --verbose

.cpp.o:
				$(CXX) -c $< -o $@ # $(INC)

all:			$(NAME)
				$(NORMAL)

$(NAME):		$(OBJ)
				$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

debug:			fclean $(NAME)
				$(DEBUG)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

tests:			fclean
				# compile

tests_run:		tests
				./$(NAME)

.PHONY:			all clean fclean re debug tests tests_run
