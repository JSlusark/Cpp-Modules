#include "../headers/ScalarConverter.hpp"

/* Default constructor */
ScalarConverter::ScalarConverter()
{
logMessage(NULL, "ScalarConverter created by default constructor");
}

// /* Parametarised constructor */
// ScalarConverter::ScalarConverter(/*const attr1, attr2*/)
// {
// 	logMessage(NULL, "ScalarConverter created by parametarised constructor");
// }

/* Copy constructor: constructs new object as a copy of an object */
ScalarConverter::ScalarConverter(const ScalarConverter &other) // : _attr1(other.attr1), _attr2(other.attr2)
{
	(void) other;
	logMessage(NULL, "ScalarConverter created by copy constructor");
}

/* Copy assignment operator: we copy attributes only as object was already constucted */
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		// BaseClass::operator=(other); // should add this instead if derived class
		// this->attribute = other->Attribute; // placeholder
	}
	logMessage(NULL, "ScalarConverter assigned by copy assignment operator");
	return *this;
}

/* Destructor */
ScalarConverter::~ScalarConverter()
{
	logMessage(NULL, "ScalarConverter destroyed by destructor ");
}

void ScalarConverter::convert(std::string literal){
	logMessage(LOG, "Received literal: " + literal);

	// for (int i = 0 ; i < literal.length(); i++)
	// {
	// 	logMessage(LOG, "Char: " + (literal[i] - 0));
	// 	logMessage(LOG, "Int: " + (literal[i] - 0));
	// 	logMessage(LOG, "Float: " + (literal[i] - 0));
	// 	logMessage(LOG, "Double:" + (literal[i] - 0));
	// }

}

