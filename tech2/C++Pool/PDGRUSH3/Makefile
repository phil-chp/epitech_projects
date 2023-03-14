##
## EPITECH PROJECT, 2021
## Epidash
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	MyGKrellm

CXX			=	g++

RM			=	rm -f

SRC			=	$(wildcard src/*.cpp)										\
				$(wildcard src/Core/*.cpp)									\
				$(wildcard src/Dashboard/*.cpp)								\
				$(wildcard src/Dashboard/SFML/*.cpp)						\
				$(wildcard src/Dashboard/NCurse/*.cpp)						\
				$(wildcard src/Dashboard/DashboardWidgets/*.cpp)			\
				$(wildcard src/Dashboard/DashboardWidgets/Widgets/*.cpp)	\
				$(wildcard src/Module/*.cpp)

OBJ			=	$(SRC:.cpp=.o)

INC			=	-I./includes/						\
				-I./includes/Core/					\
				-I./includes/Modules/				\
				-I./includes/Dashboard/				\
				-I./includes/Dashboard/Widgets/		\
				-I./includes/Dashboard/NCurse/		\
				-I./includes/Dashboard/SFML/

LIB			=	-lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS	=	-g0 -O3 -W -Wall -Wextra

NORMAL		=	@echo "[\e[31mNORMAL MODE\e[39m]"

.cpp.o:
				$(CC) $(CXXFLAGS) -c $< -o $@ $(INC)

all:			$(NAME)
				$(NORMAL)

$(NAME):		$(OBJ)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(LIB)

debug:			fclean $(NAME)
				$(DEBUG)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re debug tests tests_run
