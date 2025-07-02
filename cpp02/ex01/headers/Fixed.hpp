#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixedPointNumber;				 // the raw storage of the number
	static const int fractionalBits = 8; // number of bits that represent fraction, after the decimal
public:
	Fixed(/* args */);			// default constructor
	Fixed(const int number);	// int constructor
	Fixed(const float decimal); // floating point number constructor
	Fixed(const Fixed &object); // copy constructor, remember const for the ref as we just read and are not supposed to change the ref
	Fixed &operator=(const Fixed &other);
	~Fixed();						// destructor
	int getRawBits(void) const;		// returns raw value of fixed point number
	void setRawBits(int const raw); // sets raw value of fixed point number
	float toFloat(void) const;
	int toInt(void) const;
};

#endif