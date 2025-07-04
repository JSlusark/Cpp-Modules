#!/bin/bash

# Asks user for new class name
read -p "Enter new class name: " input

# Capitalizes first letter of class name
new_class="$(echo "${input:0:1}" | tr '[:lower:]' '[:upper:]')${input:1}"

# Define filenames
template_dir="template_files"
src_cpp="${template_dir}/Class.cpp"
src_hpp="${template_dir}/Class.hpp"

# Define destinationfiles
new_cpp="${new_class}.cpp"
new_hpp="${new_class}.hpp"

# Check if source files exist
if [[ ! -f "$src_cpp" || ! -f "$src_hpp" ]]; then
	echo "❌ Class.cpp or Class.hpp not found in current folder $template_dir."
	exit 1
fi

# Copy template files
cp "$src_cpp" "$new_cpp"
cp "$src_hpp" "$new_hpp"

# Replace class name and include guards in new files (macOS BSD sed requires '' after -i)
sed -i '' "s/\bClass\b/$new_class/g" "$new_cpp"
sed -i '' "s/\bClass\b/$new_class/g" "$new_hpp"

# Also replace any occurrence of the word Class (including comments, strings, etc.)
# This is already mostly done by \bClass\b but the following is more aggressive:
sed -i '' "s/Class/$new_class/g" "$new_cpp"
sed -i '' "s/Class/$new_class/g" "$new_hpp"

# Update include guard
old_guard="CLASS_HPP"
new_guard="$(echo "${new_class}_HPP" | tr '[:lower:]' '[:upper:]')"
sed -i '' "s/$old_guard/$new_guard/g" "$new_hpp"

# Update include directive in .cpp file
sed -i '' "s|#include \"\(.*\)/Class.hpp\"|#include \"\1/${new_class}.hpp\"|g" "$new_cpp"
sed -i '' "s|#include \"Class.hpp\"|#include \"${new_class}.hpp\"|g" "$new_cpp"

echo "✅ Created ${new_class}.cpp and ${new_class}.hpp with class name '$new_class'."
