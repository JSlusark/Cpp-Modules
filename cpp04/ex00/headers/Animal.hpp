#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal
{
private:
protected:
	std::string type;

public:
	Animal();								// Default constructor
	Animal(const Animal &other);			// Copy constructor
	Animal &operator=(const Animal &other); // Copy assignment operator
	virtual ~Animal();						// Destructor - why we out virtual here
	std::string getType() const;			// getter
	virtual void makeSound() const;			// why virtual ??
};

#endif
