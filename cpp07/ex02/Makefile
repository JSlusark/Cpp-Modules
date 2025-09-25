NAME      := array
CPP       := c++
CPPFLAGS  := -Wall -Wextra -Werror -std=c++98
SRCDIR    := src
INCDIR    := headers
OBJDIR    := obj

HEADERS = utils.hpp \
			Array.hpp

SRC = main.cpp

SRC       := $(addprefix $(SRCDIR)/, $(SRC))
OBJ       := $(addprefix $(OBJDIR)/, $(SRC:$(SRCDIR)/%.cpp=%.o))

# Colors
RESET     := \033[0m
SUCCESS     := \033[0;92m
WARNING    := \033[38;5;208m
ERROR       := \033[0;31m


all: $(NAME)
	@echo "$(NAME) is up to date!"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(addprefix $(INCDIR)/, $(HEADERS)) | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)
	@echo "$(SUCCESS)[MAKE]:$(RESET) $(NAME) successfully compiled"

clean:
	@if [ -d $(OBJDIR) ]; then \
		rm -r $(OBJDIR); \
		echo "$(SUCCESS)[CLEAN]:$(RESET) $(NAME) Object files were removed"; \
	else \
		echo "$(WARNING)[CLEAN]:$(RESET) $(NAME) Object files were already removed"; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		rm $(NAME); \
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