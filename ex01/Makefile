# Compiler config
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror
CXXFLAGS	+=	-pedantic
LDFLAGS		=	-fsanitize=address -g3

#CXX			+=	$(CXXFLAGS) $(LDFLAGS)

# Utilities
RM			=	rm -f

# Binary name
NAME		=	RPN

# Sources
SRCS		=	main.cpp RPN.cpp
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
			@echo "Prueba 1: resultado esperado 42"
			@echo "----------------------------------"
			@printf "\n"
			./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
			@printf "\n"
			@echo "Prueba 2: resultado esperado 42"
			@echo "----------------------------------"
			@printf "\n"
			./$(NAME) "7 7 * 7 -"
			@printf "\n"
			@echo "Prueba 3: resultado esperado 0"
			@echo "----------------------------------"
			@printf "\n"
			./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
			@printf "\n"
			@echo "Prueba 4: resultado esperado Error"
			@echo "----------------------------------"
			@printf "\n"
			./$(NAME) "(1 + 1)"

cleandbg:
			@$(RM) -r $(NAME).dSYM

.PHONY:		all re clean fclean