#include <iostream>
#include "../headers/Fixed.hpp"
#include <ostream> // needed for std::ostream

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) // operator overload
{
	out << fixed.toFloat();
	return out;
}

int main(void)
{
	Fixed a;														 // default constructor
	Fixed const b(10);												 // int constructor
	Fixed const c(42.42f);											 // float constructor
	Fixed const d(b);												 // copy constructor, copy assignmen is missing
	a = Fixed(1234.4321f);											 // florat constrcutoe, copy assignment appears, destructor appears
	std::cout << "a is " << a << std::endl;							 // 1234.43 ✅
	std::cout << "b is " << b << std::endl;							 // 10 ✅
	std::cout << "c is " << c << std::endl;							 // 42.4219 ✅
	std::cout << "d is " << d << std::endl;							 // 10 ✅
	std::cout << "a is " << a.toInt() << " as integer" << std::endl; // 1234 ✅
	std::cout << "b is " << b.toInt() << " as integer" << std::endl; // 10 ✅
	std::cout << "c is " << c.toInt() << " as integer" << std::endl; // 42 ✅
	std::cout << "d is " << d.toInt() << " as integer" << std::endl; // 10 ✅
	return 0;
}