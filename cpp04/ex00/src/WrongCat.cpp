#include "../headers/WrongCat.hpp"

/* Default constructor */
WrongCat::WrongCat() : WrongAnimal()
{
	type = "🐯Wrong Cat🐯";
	std::cout << "🐯WrongCat🐯 created by default constructor " << std::endl;
}

/* Copy constructor */
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "🐯WrongCat🐯 created by copy constructor " << std::endl;
}

/* Copy assignment operator */
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other); // should add this instead if derived class
	}
	std::cout << "🐯WrongCat🐯 assigned by copy assignment " << std::endl;
	return *this;
}

/* Destructor */
WrongCat::~WrongCat()
{
	std::cout << "🐯WrongCat🐯 destroyed by destructor " << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "🐯Wrong cat sound🐯" << std::endl;
}