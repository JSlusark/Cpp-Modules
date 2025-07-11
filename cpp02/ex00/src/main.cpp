#include <iostream>
#include "../headers/Fixed.hpp"

int main(void)
{
	Fixed a;	// default constructor
	Fixed b(a); // copy constructor, we initialise the object as a copy
	Fixed c;	// default constructor
	c = b;		// copy assignment operator - we assign copied members to an object that was already constructed
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}