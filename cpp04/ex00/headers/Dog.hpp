#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
private:
public:
	Dog();							  // Default constructor
	Dog(const Dog &other);			  // Copy constructor
	Dog &operator=(const Dog &other); // Copy assignment operator
	~Dog();							  // Destructor
	void makeSound() const;			  // why oveeride?
};

#endif
