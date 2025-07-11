#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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
	~Fixed(); // destructor
	// getters and setters
	int getRawBits(void) const;		// returns raw value of fixed point number
	void setRawBits(int const raw); // sets raw value of fixed point number
	// coversion functions
	float toFloat(void) const;
	int toInt(void) const;
	// comparison operator functions - they all compare the internal _fixedpointnumber
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	// arythmetic operator functions - the return a fixed object
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const; // converts a fixed to float for safe arythmentic and the return needs to be converted back to fixed using float constructor
	Fixed operator/(const Fixed &other) const; // converts a fixed to float for safe arythmentic and the return needs to be converted back to fixed using float constructor
	// increment/decrement operator functions - the return a fixed object
	Fixed &operator++(); // ++a (pre-increment)
	Fixed &operator--(); // --a (pre-decrement)
	// Post-increment/decrement
	Fixed operator++(int); // a++ (post-increment)
	Fixed operator--(int); // a-- (post-decrement)

	// min/max static member functions
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif