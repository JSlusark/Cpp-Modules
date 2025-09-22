#include "../headers/ScalarConverter.hpp"
#include <functional>

static bool is_speudoLiteral(const std::string &s)
{
	const std::string pseudos[6] = {
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (size_t i = 0; i < 6; i++)
	{
		if (s == pseudos[i])
			return true;
	}
	return false;
}

static bool isInt(const std::string &s)
{
	std::istringstream iss(s);
	int val;						 // val to store
	iss >> std::noskipws >> val;	 // do not skip spaces
	return iss.eof() && !iss.fail(); // if we are at end of stream and operation did not fail
}

static bool isFloat(const std::string &s)
{
	int back = s.length() - 1;
	if (s.empty() || s[back] != 'f')
		return false;
	std::string dup = s.substr(0, back);
	std::istringstream iss(dup);
	float val;
	iss >> std::noskipws >> val;
	return iss.eof() && !iss.fail();
}

static bool isDouble(const std::string &s)
{
	std::istringstream iss(s);
	double val;
	iss >> std::noskipws >> val;
	return iss.eof() && !iss.fail();
}

MessageType ScalarConverter::match_type(const std::string &s)
{
	if (is_speudoLiteral(s))
		return SPEUDOLITERAL;
	else if (s.length() == 1 && !isdigit(s[0]) && isprint(s[0]))
		return CHAR;
	else if (isInt(s))
		return INT;
	else if (isFloat(s))
		return FLOAT;
	else if (isDouble(s))
		return DOUBLE;
	else
		return INVALID;
};
