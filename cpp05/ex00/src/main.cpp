#include <iostream>
#include "../headers/Bureaucrat.hpp"

int main() {
    // Valid construction
    try {
        Bureaucrat a("Alice", 75);
        std::cout << a << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Invalid construction: too low
    try {
        Bureaucrat b("Bob", 151);
        std::cout << b << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Invalid construction: too high
    try {
        Bureaucrat c("Charlie", 0);
        std::cout << c << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Increment until exception
    try {
        Bureaucrat d("Diana", 2);
        std::cout << d << std::endl;
        d.incrementGrade();   // ok -> grade 1
        std::cout << d << std::endl;
        d.incrementGrade();   // throws
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Decrement until exception
    try {
        Bureaucrat e("Eve", 149);
        std::cout << e << std::endl;
        e.decrementGrade();   // ok -> grade 150
        std::cout << e << std::endl;
        e.decrementGrade();   // throws
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
