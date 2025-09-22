#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <limits>
#include <iomanip>
#include <cctype>
#include <cmath>


#include "../headers/utils.hpp"

struct t_convert
{
	std::string (*type)(const std::string &);	 // predicate: is this the type?
	void (*convert)(const std::string &literal); // action: convert + print
};

enum MessageType
{
	SPEUDOLITERAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

class ScalarConverter
{
private:
	ScalarConverter(); // Default constructor
	// ScalarConverter(/*const attr1, attr2*/);  // Parametarised constructor
	ScalarConverter(const ScalarConverter &other);			  // Copy constructor
	ScalarConverter &operator=(const ScalarConverter &other); // Copy assignment operator
	~ScalarConverter();										  // Destructor

	static MessageType match_type(const std::string &s);

public:
	static void convert(const std::string &literal); // static method to convert the literal to char, int, float, double
};

#endif
