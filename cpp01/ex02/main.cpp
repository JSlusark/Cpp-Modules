#include <iostream>
#define C_RESET "\033[0m"
#define C_RED "\033[38;2;255;85;85m"
#define C_GREEN "\033[38;2;0;255;128m"
#define C_MAGENTA "\033[38;2;255;0;255m"

int main()
{

    std::string strVar = "HI THIS IS BRAIN";
    std::string *strPtr = &strVar; // creates a pointer that points to value(*strPtr) and stores address(strPtr)
    std::string &strRef = strVar; // creates a reference to 

    std::cout << std::endl
              << C_GREEN << "Value Address: " << C_RESET << &strVar << std::endl;
    std::cout << C_RED << "Pointer Address: " << C_RESET << strPtr << std::endl;
    std::cout << C_MAGENTA << "Reference Address: " << C_RESET << &strRef << std::endl;
    std::cout << std::endl
              << C_GREEN << "Value Value: " << C_RESET << strVar << std::endl;
    std::cout << C_RED << "Pointer Value: " << C_RESET << *strPtr << std::endl;
    std::cout << C_MAGENTA << "Reference Value: " << C_RESET << strRef << std::endl;
    std::cout << std::endl;

    return 0;
}