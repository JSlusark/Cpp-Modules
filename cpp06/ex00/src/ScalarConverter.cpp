#include "../headers/ScalarConverter.hpp"

//_________________________________________________________

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

void convertToPseudoLiteral(const const std::string &str) {};
void convertToChar(const const std::string &str) {};
void convertToInt(const const std::string &str) {};
void convertToFloat(const const std::string &str) {};
void convertToDouble(const const std::string &str) {};
void convertInvalid(const const std::string &str) {};

bool is_speudoLiteral(const std::string &str)
{
	if (str == "+inf" || str == "-inf" || str == "nan" ||
		str == "+inff" || str == "-inff" || str == "nanf")
		return true;
	return false;
}
bool is_char(const std::string &str)
{
	// a sting needs to have at least one character but if just null it will be not printable no?
	// if(str.length() < 1)
	// 	return false;
	// each char has to be printable and not a digit
	for (int i = 0; i < str.length(); i++)
	{
		if (!isprint(str[i]) || isdigit(str[i]))
			return false;
	}
}

bool is_int(const std::string &str)
{
	// an int can be prefixed with + or - sign
	int start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	for (start; start < str.length(); start++)
	{
		if (!isdigit(str[start]))
			return false;
	}
}

bool is_float(const std::string &str)
{
	// unsure if i should also allow e here
	// shoudl also add .
	int start = 0;
	if (str[str.length() - 1] != 'f')
		return false;
	if (str[0] == '+' || str[0] == '-')
		start++;
	for (start; start < str.length() - 2; start++) // -2 to ignore f at the end
	{
		if (!isdigit(str[start]))
			return false;
	}
}

bool is_double(const std::string &str)
{
	// an int can be prefixed with + or - sign
	int start = 0;
	int dot_count = 0;
	if (str[0] == '.' || str[str.length() - 1] == '.') // cannot end or start
		return false;
	if (str[0] == '+' || str[0] == '-')
		start++;
	for (start; start < str.length(); start++)
	{
		if (str[start] == '.')
		{
			dot_count++;
			if (dot_count > 1) // only one dot allowed
				return false;
		}
		else
		{
			if (!isdigit(str[start]))
				return false;
		}
	}
}

MessageType match_type(const std::string &s)
{
	if (is_speudoLiteral(s))
		return SPEUDOLITERAL;
	if (is_char(s))
		return CHAR;
	if (is_int(s))
		return INT;
	if (is_float(s))
		return FLOAT;
	if (is_double(s))
		return DOUBLE;
	return INVALID;
};

// bool is_speudoLiteral(const std::string &str)
// {
// 	if (str == "+inf" || str == "-inf" || str == "nan" ||
// 		str == "+inff" || str == "-inff" || str == "nanf")
// 		return true;
// 	return false;
// }
// bool is_char(const std::string &str)
// {
// 	if ()
// 		return true;
// 	return false;
// }

// enum find_type(const std::string &s)
// {

// }

//_______________________________________________________________

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
	void (*convertType[])(const std::string &) = {
		convertToPseudoLiteral,
		convertToChar,
		convertToInt,
		convertToFloat,
		convertToDouble,
		convertInvalid};

	logMessage(LOG, "Received literal: " + literal);
	enum MessageType type = match_type(literal);
	convertType[type](literal); // calls conversion func of enum match
}

/*

void convertToSpeudoliteral(const const std::string &str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << std::endl;
	std::cout << "double: " << str << std::endl;
	return;
}

void convertToChar(const const std::string &str)
{
	logMessage(SUCCESS, "\"" + str + "\" can be converted to CHAR");
}
void convertToInt(const const std::string &str)
{
	logMessage(SUCCESS, "\"" + str + "\" can be converted to INT");
	// for (size_t i = 0; i < str.length(); i++)
	// {
	// 	float floatValue = static_cast<float>(str[i]);
	// 	std::cout << "float: " << floatValue;
	// 	if (floatValue - static_cast<int>(floatValue) == 0)
	// 		std::cout << ".0";
	// 	std::cout << "f" << std::endl;
	// }
}
void convertToFloat(const std::string &str)
{
	logMessage(SUCCESS, "\"" + str + "\" can be converted to FLOAT");
	// for (size_t i = 0; i < str.length(); i++)
	// {
	// 	float floatValue = static_cast<float>(str[i]);
	// 	std::cout << "float: " << floatValue;
	// 	if (floatValue - static_cast<int>(floatValue) == 0)
	// 		std::cout << ".0";
	// 	std::cout << "f" << std::endl;
	// }
}
void convertToDouble(const const std::string &str)
{
	logMessage(SUCCESS, "\"" + str + "\" can be converted to DOUBLE");
}


// 	return true;
// if (type == "int") // loop and check if no digit
// 	return true;
if (str[str.length() - 1] == 'f')
	return convertToFloat;
// if (type == "double")
// 	return convertToDouble;
logMessage(ERROR, "\"" + str + "\" is not a valid literal");
}
*/
// 	// char conversion
// 	if (value >= 0 && value <= 127 && isprint(static_cast<char>(value)))
// 		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
// 	else if (value >= 0 && value <= 127)
// 		std::cout << "char: Non displayable" << std::endl;
// 	else
// 		std::cout << "char: impossible" << std::endl;

// 	// int conversion
// 	if (value >= static_cast<double>(INT_MIN) && value <= static_cast<double>(INT_MAX))
// 		std::cout << "int: " << static_cast<int>(value) << std::endl;
// 	else
// 		std::cout << "int: impossible" << std::endl;

// 	// double conversion
// 	std::cout << "double: " << value;
// 	if (value - static_cast<int>(value) == 0)
// 		std::cout << ".0";
// 	std::cout << std::endl;
