##
## EPITECH PROJECT, 2020
## makefileds
## File description:
## dcd
##

SRC		=	main.c					\
			eval_expr.c				\
			calculator/infin_add.c	\
			calculator/infin_div.c	\
			calculator/infin_mult.c	\
			calculator/infin_mod.c

NAME	=	calc

LIB		=	/lib/

MYH		=	my.h

PERSH	=	pers.h

STRUCTH	=	eval_expr_struct.h

BISTRO	=	bistromatic.h

CFLAGS	+=	-I.$(MY)

MY		=	/include/

CC		=	gcc

all:	$(OBJ)
		make -C lib/ all
		cp -f lib/pers/$(MYH) include/$(MYH)
		cp -f lib/pers/$(PERSH) include/$(PERSH)
		cp -f lib/pers/$(STRUCTH) include/$(STRUCTH)
		cp -f lib/pers/$(BISTRO) include/$(BISTRO)
		$(CC) -o $(NAME) $(SRC) $(CFLAGS) -L.$(LIB) -lmy

clean:
		rm -f $(OBJ)
		make -C lib/ clean

fclean:	clean
		rm -f $(NAME)
		make -C lib/ fclean
		rm -f include/$(MYH)
		rm -f include/$(PERSH)
		rm -f include/$(STRUCTH)
		rm -f include/$(BISTRO)

re:		fclean all
		make -C lib/ re
