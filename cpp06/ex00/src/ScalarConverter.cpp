#include "../headers/ScalarConverter.hpp"

/* Default constructor */
ScalarConverter::ScalarConverter()
{
	logMessage(NULL, "ScalarConverter created by default constructor");
}

/* Copy constructor: constructs new object as a copy of an object */
ScalarConverter::ScalarConverter(const ScalarConverter &other) // : _attr1(other.attr1), _attr2(other.attr2)
{
	(void)other;
	logMessage(NULL, "ScalarConverter created by copy constructor");
}

/* Copy assignment operator: we copy attributes only as object was already constucted */
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		// no attributes to copy
	}
	logMessage(NULL, "ScalarConverter assigned by copy assignment operator");
	return *this;
}

/* Destructor */
ScalarConverter::~ScalarConverter()
{
	logMessage(NULL, "ScalarConverter destroyed by destructor ");
}