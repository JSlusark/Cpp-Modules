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

void printError(std::string err, const char &token)
{
    logMessage(ERROR, err);
    std::cout << "Program stopped at token: '" << token << "'" << std::endl;
}

void printStack(std::stack<int> &st)
{
    std::stack<int> temp = st;
    while (!temp.empty())
    {
        std::cout << temp.top() << std::endl;
        temp.pop();
    }
}

int extractOperand(std::stack<int> &stack)
{
    int extraction = stack.top();
    stack.pop();
    return extraction;
}

bool operate(const char &token, std::stack<int> &stack)
{
    // std::cout << "\n---------------STACK----------------" << std::endl;
    // std::cout << "operator: '" << token << "'" << std::endl;
    // printStack(stack);

    if (stack.size() < 2) // helps with invalid additional operands
    {
        printError("Cannot use operator on stack with less or more than 2 operands", token);
        return false;
    }
    int right = extractOperand(stack); // as rightmost operand is always on top
    int left = extractOperand(stack);

    int res;
    switch (token)
    {
    case '+':
        res = left + right;
        break;
    case '-':
        res = left - right;
        break;
    case '/':
        if (right == 0)
            return false;
        res = left / right;
        break;
    case '*':
        res = left * right;
        break;
    default:
        printError("Found invalid token.", token);
        return false;
    };

    // std::cout << "Operation: " << left << token << right << " = " << res << std::endl;
    // std::cout << "------------------------------------\n"
    //           << std::endl;

    stack.push(res);
    return true;
}

bool isNumber(const std::string &token)
{
    for (size_t i = 0; i < token.length(); i++)
    {
        if (!isdigit(token[i]))
        {
            // std::cout << "\nis not digit:'" << token << "'";
            return false;
        }
    }
    return true;
}

void printResult(int argc, char **argv)
{
    (void)argc;
    std::stack<int> stack;
    std::istringstream iss(argv[1]);
    std::string token;

    while (iss >> token) // lostack thourgh every character delimited by a sspace
    {
        // std::cout << token << std::endl;
        if (isNumber(token))
        {
            if (isNumber(token))
                stack.push(atol(token.c_str()));
        }
        else
        {
            if (!operate(token[0], stack))
            {
                std::cout << "Error" << std::endl;
                return;
            }
        }
        // stack.push(token);

        /*
        if (token.size() == 1 && std::string("+-x/").find(token) != std::string::npos)
        {
            if (stack.size() < 2) // is size i
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            if (token == "+")
                stack.push(a + b);
            else if (token == "-")
                stack.push(a - b);
            else if (token == "*")
                stack.push(a * b);
            else if (token == "/")
            {
                if (b == 0)
                {
                    std::cerr << "Error" << std::endl;
                    return 1;
                }
                stack.push(a / b);
            }
        }

        else if (isdigit(token[0]) && token.size() == 1) //
        stack.push(token[0] - '0');

        else
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        */
    }
    if (stack.size() > 1)
        logMessage(ERROR, "Operands where added without a matching operator.\nCannot return a result as stack contains more than 1 number:");
    printStack(stack);

    /* if (stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << stack.top() << std::endl;

    */
}
//     std::stack<std::string> operation;
//     std::stack<std::string> operands;
//     int tokens[] = {};
//     // std::stack<std::string> used;

//     // int result = 0;

//     // collected.push();

//     (void)argv;

//     for (int i = 1; i < argc; i++) // loop through each argument if argc > 1
//     {
//         std::istringstream iss(argv[i]); // Creates a string stream from the argument
//         std::string token;
//         int j = 0;
//         while (iss >> token) // Splits each argv[i] by spaces and collect tokens
//         {
//             std::cout << "Token [" << i << "][" << j << "]: '" << token << "'" << std::endl;
//             if (isNumber(token))
//             {
//                 tokens[j] = atol(token.c_str()); // convert string to long
//                 std::cout << "Token " << j << ": '" << tokens[j] << "'" << std::endl;
//             }
//             else if (operate(token))
//             {
//                 if(operands.size() < 2)
//                 {
//                     logMessage(ERROR, "Not enough operands for the " + token + " operation");
//                     return;
//                 }
//                 std::cout << "Token " << j << ": '" << tokens[j] << "'" << std::endl;
//             }
//             else
//             {
//                 logMessage(ERROR, "Invalid token: " + token);
//                 return;
//             }

//             // logMessage(DEBUG, "Collected token: " + tokens[j]);
//             j++;
//         }
//     }
// }
