NAME = MoarBrainz
CPP = c++  # or g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = Zombie.hpp

SRC = main.cpp \
	Zombie.cpp \
	NewZombie.cpp \
	RandomChump.cpp \
	ZombieHorde.cpp

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