#!/bin/bash
set -euo pipefail

# -------- Config --------
template_dir="template_files"      # optional: Makefile, main.cpp
proj_dir="ex0"
src_dir="${proj_dir}/src"
hdr_dir="${proj_dir}/headers"
mkfile="${proj_dir}/Makefile"

# ------- Helpers --------
capfirst() {
  local s="$1"
  printf "%s%s" "$(echo "${s:0:1}" | tr '[:lower:]' '[:upper:]')" "${s:1}"
}

ensure_dirs() {
  mkdir -p "$src_dir" "$hdr_dir"
}

copy_or_stub_makefile() {
  if [[ -f "${template_dir}/Makefile" ]]; then
    cp "${template_dir}/Makefile" "$mkfile"
  else
    cat >"$mkfile" <<'EOF'
# Minimal Makefile (auto-generated)
NAME      := program
CPP       := c++
CPPFLAGS  := -Wall -Wextra -Werror -std=c++98
SRCDIR    := src
INCDIR    := headers
OBJDIR    := obj

HEADERS =
SRC = main.cpp

SRC       := $(addprefix $(SRCDIR)/, $(SRC))
OBJ       := $(addprefix $(OBJDIR)/, $(SRC:$(SRCDIR)/%.cpp=%.o))

# Colors
RESET     := \033[0m
SUCCESS   := \033[0;92m
WARNING   := \033[38;5;208m
ERROR     := \033[0;31m

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
EOF
  fi
}

copy_or_stub_main() {
  if [[ -f "${template_dir}/main.cpp" ]]; then
    cp "${template_dir}/main.cpp" "${src_dir}/main.cpp"
  else
    cat > "${src_dir}/main.cpp" <<'EOF'
#include <iostream>
int main() {
  std::cout << "hello\n";
  return 0;
}
EOF
  fi
}

ensure_var_contains() {
  # ensure_var_contains VAR TOKEN   (keeps bare filenames as requested)
  local var="$1" token="$2"
  if grep -qE "^${var}[[:space:]]*=" "$mkfile"; then
    local lineno
    lineno="$(grep -nE "^${var}[[:space:]]*=" "$mkfile" | head -1 | cut -d: -f1)"
    local line
    line="$(sed -n "${lineno}p" "$mkfile")"
    if ! printf "%s" "$line" | grep -q -- "[[:space:]]${token}\([[:space:]]\|\$\)"; then
      local new="${line} ${token}"
      sed -i '' "${lineno}s#.*#${new}#" "$mkfile"
    fi
  else
    printf "%s = %s\n" "$var" "$token" >> "$mkfile"
  fi
}

ensure_src_has_main() {
  if grep -qE "^SRC[[:space:]]*=" "$mkfile"; then
    ensure_var_contains "SRC" "main.cpp"
  else
    echo "SRC = main.cpp" >> "$mkfile"
  fi
}

write_class_files() {
  local cls="$1"
  local guard
  guard="$(echo "${cls}_HPP" | tr '[:lower:]' '[:upper:]')"
  local cpp_path="${src_dir}/${cls}.cpp"
  local hpp_path="${hdr_dir}/${cls}.hpp"

  if [[ -e "$cpp_path" || -e "$hpp_path" ]]; then
    echo "⚠️  ${cls}.cpp/.hpp already exists. Skipping generation."
    return 0
  fi

  # .cpp
  cat > "$cpp_path" <<EOF
#include "../headers/${cls}.hpp"
#include <iostream>

/* Default constructor */
${cls}::${cls}()
{
	std::cout << "${cls} created by default constructor " << std::endl;
}

/* Copy constructor */
${cls}::${cls}(const ${cls} &other)
{
	(void)other;
	std::cout << "${cls} created by copy constructor " << std::endl;
}

/* Copy assignment operator */
${cls} &${cls}::operator=(const ${cls} &other)
{
	if (this != &other)
	{
		// BaseClass::operator=(other); // should add this instead if derived class
		// attribute = other.Attribute; // placeholder
	}
	std::cout << "${cls} assigned by copy assignment " << std::endl;
	return *this;
}

/* Destructor */
${cls}::~${cls}()
{
	std::cout << "${cls} destroyed by destructor " << std::endl;
}
EOF

  # .hpp
  cat > "$hpp_path" <<EOF
#ifndef ${guard}
#define ${guard}

class ${cls}
{
private:
public:
	${cls}();                             // Default constructor
	${cls}(const ${cls} &other);          // Copy constructor
	${cls} &operator=(const ${cls} &other); // Copy assignment operator
	~${cls}();                            // Destructor
};

#endif
EOF
}

make_class() {
  local input="$1"
  local cls
  cls="$(capfirst "$input")"
  if [[ ! "$cls" =~ ^[A-Za-z_][A-Za-z0-9_]*$ ]]; then
    echo "Invalid C++ identifier."
    return 1
  fi

  write_class_files "$cls"

  # Update Makefile lists with bare filenames only
  ensure_var_contains "HEADERS" "${cls}.hpp"
  ensure_var_contains "SRC"     "${cls}.cpp"

  echo "✅ Added class ${cls}:"
  echo "   - ${src_dir}/${cls}.cpp"
  echo "   - ${hdr_dir}/${cls}.hpp"
}

loop_add_classes() {
  while true; do
    read -r -p "Enter new class name (or 'exit'): " input
    [[ -z "${input:-}" ]] && continue
    [[ "$input" == "exit" ]] && break
    make_class "$input"
  done
}

# ------- Commands --------
cmd="${1:-}"

case "$cmd" in
  project)
    ensure_dirs
    copy_or_stub_makefile
    copy_or_stub_main
    ensure_src_has_main
    echo "Project scaffold ready in ${proj_dir}."
    loop_add_classes
    echo "Done."
    ;;
  add)
    if [[ ! -d "$proj_dir" || ! -d "$src_dir" || ! -d "$hdr_dir" || ! -f "$mkfile" ]]; then
      echo "❌ Missing project structure. Expected ${proj_dir}/ with src/, headers/, and Makefile."
      exit 1
    fi
    ensure_src_has_main
    loop_add_classes
    echo "Done."
    ;;
  *)
    echo "Usage:"
    echo "  $0 project   # create ex0 structure, copy Makefile, add main, then add classes"
    echo "  $0 add       # only add classes to existing ex0, update Makefile"
    exit 2
    ;;
esac
