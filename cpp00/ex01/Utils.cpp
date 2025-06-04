#include "Utils.hpp"

bool stringIsAlphaSpace(const std::string &s)
{
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (!std::isalpha(static_cast<unsigned char>(s[i])) && s[i] != ' ')
            return false;
    }
    return !s.empty();
}

bool StringIsDigits(const std::string &s)
{
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    }
    return !s.empty();
}

bool isCommand(const std::string &s)
{
    return s == "ADD" || s == "SEARCH" || s == "EXIT";
}

std::string trim(const std::string &str)
{
    std::size_t first = 0;
    while (first < str.size() && std::isspace(str[first]))
        ++first;
    std::size_t last = str.size();
    while (last > first && std::isspace(str[last - 1]))
        --last;
    return str.substr(first, last - first);
}
