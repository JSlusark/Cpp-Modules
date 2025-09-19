#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include "../headers/utils.hpp"

class ScalarConverter
{
private:
	ScalarConverter(); // Default constructor
	// ScalarConverter(/*const attr1, attr2*/);  // Parametarised constructor
	ScalarConverter(const ScalarConverter &other);			  // Copy constructor
	ScalarConverter &operator=(const ScalarConverter &other); // Copy assignment operator
	~ScalarConverter();										  // Destructor

	public:
	static void convert(std::string literal); // static method to convert the literal to char, int, float, double
};

#endif
