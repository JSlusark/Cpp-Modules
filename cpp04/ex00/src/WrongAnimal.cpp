#include "../headers/WrongAnimal.hpp"

/* Default constructor */
WrongAnimal::WrongAnimal()
{
	type = "🤖Wrong Animal🤖";
	std::cout << "🤖WrongAnimal🤖 created by default constructor " << std::endl;
}

/* Copy constructor */
WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << "🤖WrongAnimal🤖 created by copy constructor " << std::endl;
}

/* Copy assignment operator */
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "🤖WrongAnimal🤖 assigned by copy assignment " << std::endl;
	return *this;
}

/* Destructor */
WrongAnimal::~WrongAnimal()
{
	std::cout << "🤖WrongAnimal🤖 destroyed by destructor " << std::endl;
}
std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "🤖Wrong animal sound🤖" << std::endl;
}
