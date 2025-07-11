#include <iostream>
#include "../headers/Fixed.hpp"
#include <ostream> // needed for std::ostream

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	// --- Division by zero test
	std::cout << "\n--- Division by zero test ---" << std::endl;
	Fixed zero(0);
	Fixed result = b / zero; // this will crash, and it's acceptable
	std::cout << "Result of b / zero: " << result << std::endl;

	return 0;
}