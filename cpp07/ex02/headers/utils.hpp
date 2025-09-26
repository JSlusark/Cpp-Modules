
#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

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
			  << "================== TEST N" << number << ": " << title << " =================="
			  << C_RESET << std::endl;
};

/* TEMPLATES */

// template <typename T, typename I, typename F>
// void iter(T *arr, I len, F foo)
// {
// 	for (I i = 0; i < len; i++) // to ensure that the index number matches the t
// 	{
// 		foo(arr[i]);
// 	}
// }


// non-const elements
template <typename T, typename I>
void iter(T* a, I n, void (*f)(T&)) {
    for (I i = I(); i < n; ++i) f(a[i]);
}

// const elements
template <typename T, typename I>
void iter(T const* a, I n, void (*f)(T const&)) {
    for (I i = I(); i < n; ++i) f(a[i]);
}


template <typename T>
void printElement(T &element) // argument by const  ref
{
	std::cout << element << std::endl;
}

template <typename T>
void increase(T &element) // argument by ref
{
	++element;
}

template <typename T>
void randomize(T &element)
{
	element = rand() % 100;
}