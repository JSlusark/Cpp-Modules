#include "../headers/Fixed.hpp"

// Orthodox Canonical Form
//--- Constructors
Fixed::Fixed() : fixedPointNumber(0) // Default constructor
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) // Int constructor
{
	std::cout << "Int constructor called" << std::endl;
	fixedPointNumber = number << fractionalBits;
}

Fixed::Fixed(const float decimal) // Float constructor
{
	std::cout << "Float constructor called" << std::endl;
	fixedPointNumber = roundf(decimal * (1 << fractionalBits));
}

//--- Copy Constructor: used to initiate an object as a copy from another object
// source: https://courses.washington.edu/css342/zander/css332/copyeq.html
Fixed::Fixed(const Fixed &object) : fixedPointNumber(0) // defensive init to avoid garbage value
{
	std::cout << "Copy constructor called" << std::endl;

	/*
	THIS IS A BAD PRACTICE, but required by 42 test to show the copy assignment message
	This works, but is wrong because:
	- Copy constructor is meant to initialize a brand new object
	- Assignment operator is used to replaced the contents of an already initialized object, so to be appliec fter initialization
	- Using assignment here causes unnecessary default initialization + reassignment
	- Also fails with const and reference members
	- Dangerous for classes managing dynamic memory (e.g. using `new`/`delete`):
	   → assignment often calls `delete` on existing members (like `delete[] arrayPtr;`)
	   → but copy constructor is run before those members are safely initialized — may crash or cause undefined behavior.
	*/

	(*this) = object;

	/*

	Good practice alternative (what the compiler would synthesize by default):
		this->fixedPointNumber = object.fixedPointNumber;

		Or even better:
	Fixed::Fixed(const Fixed &object) : fixedPointNumber(object.fixedPointNumber)
	{
		std::cout << "Copy constructor called" << std::endl;
	}

	*/
}

//--- Copy Assignment Operator: used to replace an already initiated objectwith another
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointNumber = other.fixedPointNumber;
	return *this;
}

//--- Destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//--- Member Functions

int Fixed::getRawBits(void) const // returns raw value of fixed point number
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPointNumber;
}

void Fixed::setRawBits(int const raw) // sets raw value of fixed point number
{
	std::cout << "setRawBits member function called" << std::endl;
	fixedPointNumber = raw;
}

float Fixed::toFloat(void) const // converts the fixed-point back to float by 256(2--small8)
{
	return (fixedPointNumber / static_cast<float>(1 << fractionalBits));
}

int Fixed::toInt(void) const // converts the fixed-point value to an integer value.
{
	return (fixedPointNumber >> fractionalBits);
}

//--- Comparison Operators

bool Fixed::operator>(const Fixed &other) const { return fixedPointNumber > other.fixedPointNumber; }
bool Fixed::operator<(const Fixed &other) const { return fixedPointNumber < other.fixedPointNumber; }
bool Fixed::operator>=(const Fixed &other) const { return fixedPointNumber >= other.fixedPointNumber; }
bool Fixed::operator<=(const Fixed &other) const { return fixedPointNumber <= other.fixedPointNumber; }
bool Fixed::operator==(const Fixed &other) const { return fixedPointNumber == other.fixedPointNumber; }
bool Fixed::operator!=(const Fixed &other) const { return fixedPointNumber != other.fixedPointNumber; }

//--- Arithmetic Operators

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

//--- Increment/Decrement Operators

Fixed &Fixed::operator++()
{
	++fixedPointNumber;
	return *this;
}

Fixed &Fixed::operator--()
{
	--fixedPointNumber;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++fixedPointNumber;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--fixedPointNumber;
	return temp;
}

//--- Min/Max Static Functions

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}


// utils
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) // operator overload
{
	out << fixed.toFloat();
	return out;
}
