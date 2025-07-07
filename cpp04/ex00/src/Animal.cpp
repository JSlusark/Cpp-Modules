#include "../headers/Animal.hpp"

/* Default constructor */
Animal::Animal()
{
	type = "🐾animal🐾";
	std::cout << "🐾Animal🐾 created by default constructor " << std::endl;
}

/* Copy constructor */
Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "🐾Animal🐾 created by copy constructor " << std::endl;
}

/* Copy assignment operator */
Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "🐾Animal🐾 assigned by copy assignment " << std::endl;
	return *this;
}

/* Destructor */
Animal::~Animal()
{
	std::cout << "🐾Animal🐾 destroyed by destructor " << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "🐾Random animal sound🐾" << std::endl;
}
