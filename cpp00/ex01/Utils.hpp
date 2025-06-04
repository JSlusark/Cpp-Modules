#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <cctype>

bool stringIsAlphaSpace(const std::string &s);
bool StringIsDigits(const std::string &s);
bool isCommand(const std::string &s);
std::string trim(const std::string &str);
#endif