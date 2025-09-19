
#pragma once
#include <string>
#include <iostream>

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

inline void logMessage(const std::string &type, const std::string &message)
{
	// EXAMPLE
	// logMessage(ERROR, std::string("the user ") + user.name + " is not subscribed to " + web.domain);
	std::cout << type << message  << std::endl;
};

inline void testHeader(const int number, const std::string &title)
{
	std::cout << C_CYAN
			  << "================== TEST N" << number << ": " << title << " =================="
			  << C_RESET << std::endl;
};

/* OTHER */