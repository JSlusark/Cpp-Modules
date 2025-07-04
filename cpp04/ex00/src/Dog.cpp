#include "../headers/Dog.hpp"

/* Default constructor */
Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog created by default constructor " << std::endl;
}

/* Copy constructor */
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog created by copy constructor " << std::endl;
}

/* Copy assignment operator */
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		// no extra attributes to assign?
	}
	std::cout << "Dog assigned by copy assignment " << std::endl;
	return *this;
}

/* Destructor */
Dog::~Dog()
{
	std::cout << "Dog destroyed by destructor " << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}