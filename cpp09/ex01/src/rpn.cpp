#include "../headers/rpn.hpp"

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
        // printStack(stack);
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
        printError("Found invalid operator token.", token);
        return false;
    };

    // std::cout << "Operation: " << left << token << right << " = " << res << std::endl;
    // std::cout << "------------------------------------\n"
    //           << std::endl;

    stack.push(res);
    return true;
}

int getNumber(const std::string &s, size_t &i)
{
    std::string number;
    while (isdigit(s[i]))
        number += s[i++];
    i--; // go back to avoid that non-number chars are skipped in main loop

    return (atoi(number.c_str())); // need to also check if int mx or intmin first too
}

void printResult(int argc, char **argv)
{
    std::stack<int> stack;

    for (int i = 1; i < argc; i++)
    {
        std::string s = argv[i]; // so can handle ops inside or outside ""

        for (size_t i = 0; i < s.size(); ++i)
        {
            char token = s[i];
            // std::cout << "char:" << token << std::endl;
            if (isspace(token))
                continue; // skip spaces
            if (isdigit(token))
            {
                int number = getNumber(s, i);
                if (number > 10)
                {
                    printError("Cannot use numbers higher than 10", token);
                    return;
                }
                stack.push(number);
            }
            else if (!operate(token, stack))
                return;
        }
    }

    if (stack.size() > 1)
        logMessage(ERROR, "Operands where added without a matching operator.\nCannot return a result as stack contains more than 1 number:");
    printStack(stack);

}
