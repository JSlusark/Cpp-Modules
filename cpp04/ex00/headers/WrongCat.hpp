#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
public:
	WrongCat();									// Default constructor
	WrongCat(const WrongCat &other);			// Copy constructor
	WrongCat &operator=(const WrongCat &other); // Copy assignment operator
	~WrongCat();								// Destructor
	void makeSound();
};

#endif
