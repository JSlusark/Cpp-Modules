# Compiler and Flags
CPP       := c++
CPPFLAGS  := -Wall -Wextra -Werror -std=c++98

# Project Name
NAME      := megaphone

# Source and Object
SRC       := megaphone.cpp
OBJDIR    := obj
OBJ       := $(OBJDIR)/$(SRC:.cpp=.o)

# Colors
RESET     := \033[0m
SUCCESS     := \033[0;92m
WARNING    := \033[38;5;208m
ERROR       := \033[0;31m


all: $(NAME)
	@echo "$(NAME) is up to date!"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)
	@echo "$(SUCCESS)[MAKE]:$(RESET) $(NAME) successfully compiled"

clean:
	@if [ -d $(OBJDIR) ]; then \
		$(RM) -r $(OBJDIR); \
		echo "$(SUCCESS)[CLEAN]:$(RESET) $(NAME) Object files were removed"; \
	else \
		echo "$(WARNING)[CLEAN]:$(RESET) $(NAME) Object files were already removed"; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		$(RM) $(NAME); \
		echo "$(SUCCESS)[FCLEAN]:$(RESET) $(NAME) executable was removed"; \
	else \
		echo "$(WARNING)[FCLEAN]:$(RESET) $(NAME) executable was already removed"; \
	fi

re: fclean all


%:
	@echo "$(ERROR)[ERROR]:$(RESET) Invalid target '$@'"
	@echo "Usage:"
	@echo "  $(SUCCESS)make$(RESET)         - Build the project"
	@echo "  $(SUCCESS)make re$(RESET)      - Clean & rebuild"
	@echo "  $(SUCCESS)make clean$(RESET)   - Remove object files"
	@echo "  $(SUCCESS)make fclean$(RESET)  - Remove all generated files"

.PHONY: all clean fclean re %