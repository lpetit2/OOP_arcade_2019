NAME	=	../lib_arcade_caca.so

CXX	=	g++ -g3 -fPIC

RM	=	rm -vf

SRCS	= 	./src/lib_caca.cpp	\
			./src/menu_lib.cpp	\
			./src/game_caca.cpp	\
			./src/MyWindowC.cpp \

OBJS	=	$(SRCS:.cpp=.o)

LCACA	+=	-lcaca

MAKEFLAGS += --silent

CPPFLAGS +=	-W -Wall -Wextra -Iinclude

all: $(NAME)

$(NAME):	$(OBJS)
	printf "\033[1;34mCompiling Caca...\033[0m\n"
	$(CXX) -shared $(OBJS) -o $(NAME) $(LCACA)
	printf "[\033[1;32mCaca library built\033[0m]   \t\t\t\t\t\t\tlib_arcade_caca.so\n"

clean:
	printf "\033[1;31m[deleting]\033[0;35m\n"
	$(RM) $(OBJS)
	printf "\033[0m"

fclean: clean
	printf "\033[1;31m[deleting]\033[0;35m\n"
	$(RM) $(NAME)
	printf "\033[0m"

re: fclean all

.PHONY: all clean fclean re
