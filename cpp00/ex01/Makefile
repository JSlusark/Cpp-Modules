NAME = phonebook
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
FILES = $(SRC:.cpp=.o)
HEADERS = Phonebook.hpp, Contact.hpp
OBJ = $(FILES) $(HEADERS)

all: $(NAME)

$(NAME): $(FILES)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(FILES)

	%.o: %.cpp $(DEPS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(FILES)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.phony: all clean fclean