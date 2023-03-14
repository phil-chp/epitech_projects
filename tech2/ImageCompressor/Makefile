##
## EPITECH PROJECT, 2022
## Adrian Lorenzi
## File description:
## day2
##

MAKEFLAGS	=	-s

NAME 		= 	imageCompressor

STACK 		=	stack
CP 			= 	cp -f
RM 			= 	rm -f

HSFLAGS		=	--verbosity warn --ghc-options="-O3 -g0 -W -Wall -Wextra"

PRFLAGS		=	-p # -h

MSG_PREV	=	@/bin/echo -e "[\e[32m$(NAME)\e[39m] Building project..."
MSG_POST	=	@/bin/echo -e "[\e[32m$(NAME)\e[39m] Build sucessful"
DEBUG_MSG	=	@/bin/echo -e "[\e[31m$(NAME)\e[39m] Debug mode enabled"
PROFILE_MSG	=	@/bin/echo -e "[\e[31m$(NAME)\e[39m] Profiler enabled"

EXEC   	 	=   $(shell stack path --local-install-root)/bin/imageCompressor

debug:		HSFLAGS	= --verbosity error --ghc-options="-O0 -g3 -W -Wall -Wextra"

profile:	HSFLAGS += --executable-profiling --library-profiling --profile --ghc-options="-fprof-auto"

all:
			$(MSG_PREV)
			$(STACK) build $(HSFLAGS)
			$(CP) $(EXEC) $(NAME)
			$(MSG_POST)

debug:		all
			$(DEBUG_MSG)

profile:	all
			$(PROFILE_MSG)
			$(STACK) exec -- $(NAME) +RTS $(PRFLAGS)

clean:
			$(STACK) clean

fclean: 	clean
			$(RM) ./$(NAME)

re:			fclean all

.PHONY:		all clean fclean re
