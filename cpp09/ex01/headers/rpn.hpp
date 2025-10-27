#include "./utils.hpp"
#include <string.h>
#include <sstream> // std::istringstream
#include <stack>
#include <cstdlib> // atoi

/*
Edgecases:

./rpn 1 #one arg
./rpn "    1    " ##one arg with len > 0
./rpn "123455"
./rpn " 1  "  " 2 3" 5 8
./rpn >INT_MAX
./rpn
./rpn
./rpn

*/

// int calculate(char **argv)
// {
//     int result;
//     return
// }

bool isOperator(const std::string &token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool isNumber(const std::string &token)
{
    for (size_t i = 0; i < token.length(); i++)
    {
        if (!isdigit(token[i]))
            return false;
    }
    return true;
}

void printResult(int argc, char **argv)
{
    std::stack<std::string> operation;
    std::stack<std::string> operands;
    int tokens[] = {};
    // std::stack<std::string> used;

    // int result = 0;

    // collected.push();

    (void)argv;

    for (int i = 1; i < argc; i++) // loop through each argument if argc > 1
    {
        std::istringstream iss(argv[i]); // Creates a string stream from the argument
        std::string token;
        int j = 0;
        while (iss >> token) // Splits each argv[i] by spaces and collect tokens
        {
            std::cout << "Token [" << i << "][" << j << "]: '" << token << "'" << std::endl;
            if (isNumber(token))
            {
                tokens[j] = atol(token.c_str()); // convert string to long
                std::cout << "Token " << j << ": '" << tokens[j] << "'" << std::endl;
            }
            else if (isOperator(token))
            {
                if(operands.size() < 2)
                {
                    logMessage(ERROR, "Not enough operands for the " + token + " operation");
                    return;
                }
                std::cout << "Token " << j << ": '" << tokens[j] << "'" << std::endl;
            }
            else
            {
                logMessage(ERROR, "Invalid token: " + token);
                return;
            }

            // logMessage(DEBUG, "Collected token: " + tokens[j]);
            j++;
        }
    }
}
