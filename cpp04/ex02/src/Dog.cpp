#include "../headers/Dog.hpp"

/* Default constructor */
Dog::Dog() : Animal()
{
	this->type = "🐶Dog🐶";
	brain = new Brain();
	std::cout << " 🐶Dog🐶 created by default constructor " << std::endl;
}

/* Copy constructor */
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << " 🐶Dog🐶 created by copy constructor " << std::endl;
	brain = new Brain(*other.brain);
}

/* Copy assignment operator */
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		// this->brain = other.brain; // <--- shallow copy, both objects (cat/dog) would point to the same Brain in memory (as Shallow copying a pointer just copies the memory addres)
		delete brain; // as we already init before copy op for sure
		brain = new Brain(*other.brain); //  both objects have independent Brain instances, we use this copy with pointers
		// no extra attributes to assign?
	}
	std::cout << " 🐶Dog🐶 assigned by copy assignment " << std::endl;
	return *this;
}

/* Destructor */
Dog::~Dog()
{
	delete brain;
	std::cout << " 🐶Dog🐶 destroyed by destructor " << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "🐶Woof Woof🐶" << std::endl;
}