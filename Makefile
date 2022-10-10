##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile Defender
##

REDDARK=\033[31;2m
RED=\033[31;1m
GREEN=\033[32;1m
YEL=\033[33;1m
BLUE=\033[34;1m
PINK=\033[35;1m
CYAN=\033[36;1m
RES=\033[0m

SRC		=	src/main.cpp		    \
			src/Exec/Exec.cpp	\
			src/Factory/Factory.cpp	\
			src/Component/C4001.cpp	\
			src/Component/C4011.cpp	\
			src/Component/C4030.cpp	\
			src/Component/C4071.cpp	\
			src/Component/C4081.cpp	\
			src/Component/C4069.cpp	\
			src/Component/Clock.cpp	\
			src/Component/Input.cpp	\
			src/Component/Output.cpp	\
			src/Component/True.cpp	\
			src/Component/False.cpp	\
			src/Error/ErrorParser.cpp	\
			src/Error/Error.cpp	\
			src/printState.cpp	\
			src/Gates/Gates.cpp	\
			src/Parser/Parser.cpp



CPPFLAGS 	+=	-std=c++20 -I include -g

OBJ     =   $(SRC:.cpp=.o)

NAME    =    nanotekspice

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS)
	@echo -e "$(RED)$(NAME) $(GREEN)[✘]$(RES)"

all: 	$(NAME)

clean:
	rm -f $(OBJ)


fclean: clean
		rm -f $(NAME)

re:		fclean all