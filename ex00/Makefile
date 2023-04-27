# Compiler config
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror
CXXFLAGS	+=	-pedantic
LDFLAGS		=	-fsanitize=address -g3

#CXX			+=	$(CXXFLAGS) $(LDFLAGS)

# Utilities
RM			=	rm -f

# Binary name
NAME		=	btc

# Sources
SRCS		=	main.cpp BitcoinExchange.cpp
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
			./btc input.csv

run1:		re cleandbg
			./btc data.csv

cleandbg:
			@$(RM) -r $(NAME).dSYM

.PHONY:		all re clean fclean