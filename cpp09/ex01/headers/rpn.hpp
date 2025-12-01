#pragma once
#include "./utils.hpp"
#include <string.h>
#include <sstream> // std::istringstream
#include <stack>
#include <cstdlib> // atoi


void printError(std::string err, const char &token);
void printStack(std::stack<int> &st);
int extractOperand(std::stack<int> &stack);
bool operate(const char &token, std::stack<int> &stack);
int getNumber(const std::string &s, size_t &i);
void printResult(int argc, char **argv);
