NAME = UnnecessaryViolence
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = HumanA.hpp \
	HumanB.hpp \
	Weapon.hpp

SRC = main.cpp \
	HumanA.cpp \
	HumanB.cpp \
	Weapon.cpp


OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp $(HEADERS) | $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re