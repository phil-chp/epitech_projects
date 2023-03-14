##
## EPITECH PROJECT, 2020
## makefileds
## File description:
## dcd
##

NAME	=	eval_expr

LIB	=	/lib/

MYH	=	my.h

PERSH	=	pers.h

STRUCTH	=	eval_expr_struct.h

CFLAGS	+=	-I.$(MY)

MY	=	/include/

CC	=	gcc

all	:	$(OBJ)
		make -C lib/ all
		cp -f lib/pers/$(MYH) include/$(MYH)
		cp -f lib/pers/$(PERSH) include/$(PERSH)
		cp -f lib/pers/$(STRUCTH) include/$(STRUCTH)
		$(CC) -o $(NAME) main.c eval_expr.c calculator/*.c $(CFLAGS) -L.$(LIB) -lmy

clean	:
		rm -f $(OBJ)
		make -C lib/ clean

fclean	:	clean
		rm -f $(NAME)
		make -C lib/ fclean
		rm -f include/$(MYH)
		rm -f include/$(PERSH)
		rm -f include/$(STRUCTH)

re	:	fclean all
		make -C lib/ re
