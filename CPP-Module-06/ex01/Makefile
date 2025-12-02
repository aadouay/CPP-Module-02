NAME    = Bureaucrat_sign_form
CPP     = c++
FLAGS   = -std=c++98 -Wall -Wextra -Werror
RM      = rm -rf


SRC  = main.cpp Bureaucrat.cpp Form.cpp
OBJ     = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) -o $(NAME) $(OBJ)
%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	clean
.SECONDARY: $(OBJ)