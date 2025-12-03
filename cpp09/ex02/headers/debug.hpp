/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:01:50 by jslusark          #+#    #+#             */
/*   Updated: 2025/12/03 13:01:52 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <deque>
#include <string>
#include <sstream>

/* ------------------------------COLOR CODES----------------------------- */

#define C_RESET "\033[0m"
#define C_GREEN "\033[38;2;0;255;128m"
#define C_YELLOW "\033[38;2;255;255;0m"
#define C_RED "\033[38;2;255;85;85m"
#define C_MAGENTA "\033[38;2;255;0;255m"
#define C_PURPLE "\033[38;2;180;0;255m"
#define C_CYAN "\033[38;2;0;255;255m"
#define C_LGRAY "\033[38;2;150;150;150m"
#define C_GRAY "\033[38;2;80;80;80m"

/* --------------------- LOGGERS --------------------- */
#define LOG C_LGRAY "[LOG] " C_RESET
#define SUCCESS C_GREEN "[SUCCESS] " C_RESET
#define WARNING C_YELLOW "[WARNING] " C_RESET
#define ERROR C_RED "[ERROR] " C_RESET
#define EXCEPTION C_RED "[EXCEPTION] " C_RESET
#define DEBUG C_CYAN "[DEBUG] " C_RESET

#define DEFAULT_C C_YELLOW "[DEFAULT CONSTRUCTOR] " C_RESET
#define PARAM_C C_YELLOW "[PARAMETARISED CONSTRUCTOR] " C_RESET
#define COPY_C C_YELLOW "[COPY CONSTRUCTOR] " C_RESET
#define ASSIGN_OP C_YELLOW "[ASSIGNMENT OPERATOR] " C_RESET
#define DESTRUCTOR C_YELLOW "[DESTRUCTOR] " C_RESET



inline void logMessage(const std::string &type, const std::string &message)
{
	// EXAMPLE
	// logMessage(ERROR, std::string("the user ") + user.name + " is not subscribed to " + web.domain);
	std::cout << type << message << std::endl;
};
inline void testTitle(const int number, const std::string &title)
{
	std::cout << C_CYAN
			  << "=== TEST N" << number << ": " << title << " ==="
			  << C_RESET << std::endl;
};


/* ---------------------- UNAVAILABLE CPP98 FUNCTIONS --------------------- */
inline std::string asString(double value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}
