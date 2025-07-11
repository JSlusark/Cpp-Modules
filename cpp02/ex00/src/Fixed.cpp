#include "../headers/Fixed.hpp"

// Orthodox Canonical form
Fixed::Fixed(/* args */) : fixedPointNumber(0) // default constructor
{
	std::cout << "Default costructor called" << std::endl;
}
Fixed::Fixed(const Fixed &other) // ref usually called other, copy or src for convention. We are constructing from an existing other.
{
	std::cout << "Copy costructor called" << std::endl;
	this->fixedPointNumber = other.fixedPointNumber; // //fractionalBits does not need to be copied
}
Fixed &Fixed::operator=(const Fixed &other) // other as we are replacing other's state with that of another
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->fixedPointNumber = other.fixedPointNumber; //fractionalBits does not need to be copied
	}
	return *this;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
// my functions
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPointNumber;
}; // returns raw value of fixed point number
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixedPointNumber = raw;
}; // sets raw value of fixed point number