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
	(void)other;
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

void ScalarConverter::convert(const std::string &literal)
{
	/*
	static_cast for actual value conversions.
	strtol
	strtof - converts string to float does it also parse? answer me here:
	strtod
	For printing floats/doubles use std::fixed << std::setprecision(1) like the subject examples.
	If conversion to char not printable: print "Non displayable".
	If out of range (e.g. int from huge double) → print "impossible".
	*/

	if (literal.empty() || literal.length() == 0)
	{
		logMessage(ERROR, "Empty string provided");
	}

	void (*convertType[])(const std::string &) = {
		convertToPseudoLiteral,
		convertToChar,
		convertToInt,
		convertToFloat,
		convertToDouble,
		convertInvalid};

	// logMessage(LOG, "Received literal: " + literal);
	enum MessageType type = match_type(literal);
	convertType[type](literal); // calls conversion func of enum match
}