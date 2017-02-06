SRC	=	Entity.cpp Population.cpp Selection.cpp main.cpp
OBJ	=	$(SRC:%.cpp=%.o)
NAME	=	genetic
CXX	=	g++
CXXFLAGS=	-Wall -Werror
RM	= rm -f

all: $(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all