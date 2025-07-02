#include "../headers/Fixed.hpp"
// std::cout << std::endl;

// Orthodox Canonical form

//--- constructor types
Fixed::Fixed(/* args */) : fixedPointNumber(0) // default constructor
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) : fixedPointNumber(0) // int constructor
{
	std::cout << "Int constructor called" << std::endl;
	// covert to fixed point value
	fixedPointNumber = number << fractionalBits; // << means number x 256  as (1<< 8 = 256)
}
Fixed::Fixed(const float decimal) : fixedPointNumber(0) // int constructor
{
	std::cout << "Float constructor called" << std::endl;
	// covert to fixed point value
	fixedPointNumber = roundf(decimal * (1 << fractionalBits)); // direct op with int value of fraction (1<< 8 = 256)
}
//---

Fixed::Fixed(const Fixed &object) // ref usually called object, copy or src for convention. We are constructing from an existing object.
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointNumber = object.fixedPointNumber; // good to add this for clarity, we are using member variable
}

// copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &other) // other as we are replacing object's state with that of another
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->fixedPointNumber = other.fixedPointNumber; // good to add this for clarity, we are using member variable
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

float Fixed::toFloat(void) const
{
	return (fixedPointNumber / static_cast<float>(1 << fractionalBits));
}; // converts the fixed-point back to float by 256(2--small8)
int Fixed::toInt(void) const
{
	return (fixedPointNumber >> 8); // as fixed = int << 8
}; // converts the fixed-point value to an integer value.