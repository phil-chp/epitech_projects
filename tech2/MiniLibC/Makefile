##
## EPITECH PROJECT, 2022
## MiniLibC (Workspace)
## File description:
## Makefile
##

MAKEFLAGS	=	-s

NAME		=	libasm.so

ASM			=	nasm

LD			=	ld

RM			=	rm -f

ifeq ($(shell getconf LONG_BIT), 64)
ASMFLAGS	=	-felf64
else
ASMFLAGS	=	-felf32
endif

SRC			=	$(wildcard src/*.asm)

OBJ			=	$(SRC:.asm=.o)

MSG			=	@echo "[\e[32mMiniLibC\e[39m] Compiled sucessfully"

%.o:			%.asm
				$(ASM) $(ASMFLAGS) -o $@ $<

all:			$(NAME)
				$(MSG)

$(NAME):		$(OBJ)
				$(LD) -shared -o $(NAME) $(OBJ)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

test_run:
				make all  -C ./test/

re:				fclean all

.PHONY:			all clean fclean re
