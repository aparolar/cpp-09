# Compiler config
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror
CXXFLAGS	+=	-pedantic
LDFLAGS		=	-fsanitize=address -g3

CXX			+=	$(CXXFLAGS) $(LDFLAGS)

# Utilities
RM			=	rm -f

# Binary name
NAME		=	btc

# Sources
SRCS		=	main.cpp
OBJS		=	$(SRCS:.cpp=.o)

# Targets

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(SRCS) -o $(NAME)

re:			fclean all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

run0:		re
			./btc input.csv

run1:		re
			./btc data.csv

clean_dbg:
			$(RM) -r $(NAME).dSYM

.PHONY:		all re clean fclean