#include <iostream>

int main(){

    std::string stringVAR = "HI THIS IS BRAIN";
    std::string* stringPTR = &stringVAR;
    std::string& stringREF = stringVAR;

    std::cout << "stringVAR Memory Address: " << &stringVAR << std::endl;
    std::cout << "stringPTR Memory Address: " << &stringPTR << std::endl;
    std::cout << "stringREF Memory Address: " << &stringREF << std::endl;

    std::cout << "stringVAR Memory Address: " << stringVAR << std::endl;
    std::cout << "stringPTR Memory Address: " << *stringPTR << std::endl;
    std::cout << "stringREF Memory Address: " << stringREF << std::endl;

    return 0;
}