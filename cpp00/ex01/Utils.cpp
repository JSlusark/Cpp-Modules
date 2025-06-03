#include "Utils.hpp"

bool stringIsAlphas(const std::string& s) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (!std::isalpha(static_cast<unsigned char>(s[i])))
            return false;
    }
    return !s.empty(); // Return false for empty string
}

bool StringIsDigits(const std::string& s) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    }
    return !s.empty(); // Return false for empty string
}

bool isCommand(const std::string &s)
	{
		return s == "ADD" || s == "SEARCH" || s == "EXIT";
	}
