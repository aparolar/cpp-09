# Compiler config
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror
CXXFLAGS	+=	-pedantic
#LDFLAGS		=	-fsanitize=address -g3

#CXX			+=	$(CXXFLAGS) $(LDFLAGS)

# Utilities
RM			=	rm -f

# Binary name
NAME		=	PmergeMe

# Sources
SRCS		=	main.cpp PmergeMe.cpp
OBJS		=	$(SRCS:.cpp=.o)
CXXPLUS		=	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SRCS)

# Targets

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXXPLUS) -o $(NAME)

re:			fclean all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

run0:		re cleandbg
			@clear
			@printf "\nPrueba 1 (30 numeros aleatorios)\n"
			./PmergeMe 978 1517 604 51 930 1859 1967 1822 2764 900 2366 1151 2008 1013 2218 1931 2198 2829 240 2663 231 2352 260 2858 2577 1558 767 1027 653 2027
			@printf "\n"

cleandbg:
			@$(RM) -r $(NAME).dSYM

.PHONY:		all re clean fclean