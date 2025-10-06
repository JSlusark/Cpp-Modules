
#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>

/* COLORS */
#define C_RESET "\033[0m"
#define C_GREEN "\033[38;2;0;255;128m"
#define C_YELLOW "\033[38;2;255;255;0m"
#define C_RED "\033[38;2;255;85;85m"
#define C_MAGENTA "\033[38;2;255;0;255m"
#define C_PURPLE "\033[38;2;180;0;255m"
#define C_CYAN "\033[38;2;0;255;255m"
#define C_GRAY "\033[38;2;150;150;150m"

/* --------------------- LOG TYPES --------------------- */
#define LOG C_GRAY "[LOG] " C_RESET
#define SUCCESS C_GREEN "[SUCCESS] " C_RESET
#define WARNING C_YELLOW "[WARNING] " C_RESET
#define ERROR C_RED "[ERROR] " C_RESET
#define EXCEPTION C_RED "[EXCEPTION] " C_RESET
#define DEBUG C_CYAN "[DEBUG] " C_RESET

inline void logMessage(const std::string &type, const std::string &message)
{
	// EXAMPLE
	// logMessage(ERROR, std::string("the user ") + user.name + " is not subscribed to " + web.domain);
	std::cout << type << message << std::endl;
};

inline void testTitle(const int number, const std::string &title)
{
	std::cout << C_CYAN
			  << "====== TEST N" << number << ": " << title << " ======"
			  << C_RESET << std::endl;
};

/*  TEMPLATE */

template <typename T>										   // T is a container class from the C++ standard library
typename T::const_iterator easyFind(const T &container, int to_find) // T::iterator is a nested type within the container class T
{
	// typename tells the compiler that T::iterator is a dependent type name
	typename T::const_iterator it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end())
		throw std::runtime_error("value to_find is not in container");
	return it;
}