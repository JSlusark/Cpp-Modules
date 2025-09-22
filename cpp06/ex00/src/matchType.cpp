#include "../headers/ScalarConverter.hpp"
#include <functional>

bool loopLiteral(const std::string &s, int (*matches)(int))
{
	for (size_t i = 0; i < s.length(); i++)
	{
		unsigned char c = s[i];
		if (matches(c)) // if is print, is alpha, isdigit etc
			return true;
	}
	return false; // using ! will give this
}

bool hasDup(const std::string &s, const std::string &specials)
{
	for (size_t i = 0; i < specials.length(); i++)
	{
		char c = specials[i];
		if (s.find(c) != s.rfind(c))
			return true;
	}
	return false;
}

bool is_speudoLiteral(const std::string &s)
{
	const std::string pseudoLiterals[6] = {
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (size_t i = 0; i < 6; i++)
	{
		if (s == pseudoLiterals[i])
			return true;
	}
	return false;
}

MessageType isNumber(const std::string &s)
{
	if (hasDup(s, "-+.feE")) // we check for dups before skipping i 0
	{
		// printf("INVALID 1 \n");
		return INVALID;
	}
	size_t start = 0;
	std::string s_dup = s;					// does not change if + or - found at start
	if (s[start] == '-' || s[start] == '+') // skip by one ONLY if + or - in 0
		s_dup = s.substr(1, s.length());
	size_t dup_len = s_dup.length();
	if (s_dup.empty() || s_dup.find("+") < dup_len || s_dup.find("-") < dup_len) // with cases that have only "+" of "-"
	{
		// printf("INVALID 2 \n");
		return INVALID;
	}
	if (!loopLiteral(s_dup, isalpha) && s_dup.find(".") > dup_len)
	{
		// if there are no letters, if . and f are not found ()
		return INT;
	}

	if (s_dup[start] == '.' || s_dup[dup_len - 1] == '.') // no need to find
	{
		// logMessage(DEBUG, std::to_string(s_dup[start]));
		// logMessage(DEBUG,std::to_string(s_dup.find("-")));
		return INVALID;
	}
	if (s_dup[dup_len - 1] == 'f') // if last char of float is f we have a float
	{
		s_dup = s.substr(0, s_dup[dup_len - 1]); // we check from first to 2nd last
		// printf("s_dup: %s \n", s_dup.c_str());
		// add other stuff
		return FLOAT;
	}
	// logMessage(DEBUG,std::to_string(s_dup[end]));

	return DOUBLE;
}

// main func
MessageType ScalarConverter::match_type(const std::string &s)
{

	// if (loopLiteral(s, isprint) && loopLiteral(s, isdigit))
	// 	return INT;
	if (!loopLiteral(s, isprint)) //
	{
		// printf("INVALID 0 \n");
		return INVALID;
	}
	if (is_speudoLiteral(s)) // no need to loop its a full match
		return SPEUDOLITERAL;
	else if (!loopLiteral(s, isdigit) && s.length() == 1) // unsure if can be a full string or just one char
	{
		// printf("CHAR!!!! \n");
		return CHAR;
	}
	else
		return isNumber(s);
};
