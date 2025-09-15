#include "../headers/Class.hpp"

/* Default constructor */
Class::Class()
{
	std::cout << "Class created by default constructor " << std::endl;
}

/* Copy constructor */
Class::Class(const Class &other)
{
	std::cout << "Class created by copy constructor " << std::endl;
}

/* Copy assignment operator */
Class &Class::operator=(const Class &other)
{
	if (this != &other)
	{
		// BaseClass::operator=(other); // should add this instead if derived class
		attribute = other.Attribute;
	}
	std::cout << "Class assigned by copy assignment " << std::endl;
	return *this;
}

/* Destructor */
Class::~Class()
{
	std::cout << "Class destroyed by destructor " << std::endl;
}