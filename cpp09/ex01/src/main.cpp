#include <iostream>
#include <stack>
#include <sstream>

#include "../headers/rpn.hpp"
/*
- it will not show error when is not number or operator
- needs to handle any number besides decimals -> so only int is fine
- needs to send error when n / 0 at any moment not just end
- needs to handle when writing more args (with or without different "")
- needs to avoid starting with an op
- works only with n < 9
- i decided not to handle negative nums and handle when chars are close to eachother

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "(1 + 1)"

/*
Edgecases:

./RPN 1 #one arg
result = 1

./RPN "    1    " ##one arg with len > 0
result = 1

./RPN "123455"
result = error

./RPN " 1  "  " 2+ 3-" 5 8 ++
result =13

./RPN " 1 "  " 2 3+-" 5 8 ++
result =9

./RPN " 1 +-"  " 2 3" 5 8 ++
result = error

./RPN
result = error

*/


*/

int main(int argc, char **argv)
{
    if (argc < 2) // idk
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    else
    {
        printResult(argc, argv);
    }
}

//     std::stack<std::string> ops;
//     std::istringstream iss(argv[1]);
//     std::string token;

//     while (iss >> token) // loops thourgh every character delimited by a sspace
//     {
//         if(token)
//         std::cout << "token: " << token << std::endl;
//         ops.push(token);

//         /*
//         if (token.size() == 1 && std::string("+-x/").find(token) != std::string::npos)
//         {
//             if (ops.size() < 2) // is size i
//             {
//                 std::cerr << "Error" << std::endl;
//                 return 1;
//             }
//             int b = ops.top();
//             ops.pop();
//             int a = ops.top();
//             ops.pop();

//             if (token == "+")
//                 ops.push(a + b);
//             else if (token == "-")
//                 ops.push(a - b);
//             else if (token == "*")
//                 ops.push(a * b);
//             else if (token == "/")
//             {
//                 if (b == 0)
//                 {
//                     std::cerr << "Error" << std::endl;
//                     return 1;
//                 }
//                 ops.push(a / b);
//             }
//         }

//         else if (isdigit(token[0]) && token.size() == 1) //
//         ops.push(token[0] - '0');

//         else
//         {
//             std::cerr << "Error" << std::endl;
//             return 1;
//         }
//         */
//     }

//     /* if (ops.size() != 1)
//     {
//         std::cerr << "Error" << std::endl;
//         return 1;
//     }

//     std::cout << ops.top() << std::endl;

//     */

// }

/* tests

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "8 9* 9 - 9 - 9 - 4 - 1 +"
./RPN "8 9 * 9" "- 9 - 9 - 4 - 1 +"

42

./RPN "7 7 * 7 -"
42

./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "1 2 * 2 / 0 * 2 4 - +" <------- error /0 does not trigger

0

./RPN "(1 + 1)"
Error

*/