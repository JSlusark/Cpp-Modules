#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixedPointNumber;
	static const int fractionalBits = 8; // static is shared thorugh all instances of Fixed, const is fixed at compile time, only exists once not per object
public:
	Fixed(/* args */);			// default constructor
	Fixed(const Fixed &object); // copy constructor, remember const for the ref as we just read and are not supposed to change the ref
	Fixed &operator=(const Fixed &other);
	~Fixed();						// destructor
	int getRawBits(void) const;		// returns raw value of fixed point number
	void setRawBits(int const raw); // sets raw value of fixed point number
};

#endif