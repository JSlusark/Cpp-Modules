#include <iostream>
#include "../headers/Fixed.hpp"

int main(void)
{
	Fixed a;			   // default constructor
	Fixed const b(10);	   // int constructor
	Fixed const c(42.42f); // float constructor
	Fixed const d(b);	   // even if the test asks us to show the copy assignment message, there should be no assignment as we are initialising the class!!
	// Fixed d(b);
	// d = b;
	a = Fixed(1234.4321f);											 // florat constrcutoe, copy assignment appears, destructor appears
	// sends data to the output stream
	std::cout << "a is " << a << std::endl;							 // 1234.43  (a is a fixed object)
	std::cout << "b is " << b << std::endl;							 // 10 
	std::cout << "c is " << c << std::endl;							 // 42.4219 
	std::cout << "d is " << d << std::endl;							 // 10 
	std::cout << "a is " << a.toInt() << " as integer" << std::endl; // 1234 
	std::cout << "b is " << b.toInt() << " as integer" << std::endl; // 10 
	std::cout << "c is " << c.toInt() << " as integer" << std::endl; // 42 
	std::cout << "d is " << d.toInt() << " as integer" << std::endl; // 10 
	return 0;
}