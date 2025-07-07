#include "../headers/Cat.hpp"

/* Default constructor */
Cat::Cat() : Animal()
{
	this->type = "🐱Cat🐱";
	std::cout << "🐱Cat🐱 created by default constructor " << std::endl;
}

/* Copy constructor */
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "🐱Cat🐱 created by copy constructor " << std::endl;
}

/* Copy assignment operator */
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		// no extra attributes to assign?
	}
	std::cout << "🐱Cat🐱 assigned by copy assignment " << std::endl;
	return *this;
}

/* Destructor */
Cat::~Cat()
{
	std::cout << "🐱Cat🐱 destroyed by destructor " << std::endl;
}
void Cat::makeSound() const
{
	std::cout << "🐱Meow Meow🐱" << std::endl;
}