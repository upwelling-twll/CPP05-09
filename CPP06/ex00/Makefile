SRCS	=	main.cpp ScalarConverter.cpp

NAME	=	ScalarConverter

OBJ	=	$(SRCS:.cpp=.o)

CXX	=	c++

CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 #-fsanitize=address -g3

all	:	$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) 

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -v $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re