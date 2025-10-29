#include <iostream>
#include <stack>
#include <sstream>

/* 
needs to handle any number besides decimals: 100, 1, -2
needs to send error when n / 0 at any moment not just end
- needs to handle when writing  args in different ""
- needs to avoid starting with an op


*/

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::stack<int> stack;
    std::istringstream iss(argv[1]);
    std::string token;

    while (iss >> token) // loops thourgh every character delimited by a sspace
    {
        if (token.size() == 1 && std::string("+-*/").find(token) != std::string::npos)
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
    }

    if (stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << stack.top() << std::endl;
}


/* tests

$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
$> ./RPN "8 9* 9 - 9 - 9 - 4 - 1 +"
./RPN "8 9 * 9" "- 9 - 9 - 4 - 1 +"

42

$> ./RPN "7 7 * 7 -"
42

$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "1 2 * 2 / 0 * 2 4 - +" <------- error /0 does not trigger

0

$> ./RPN "(1 + 1)"
Error

*/