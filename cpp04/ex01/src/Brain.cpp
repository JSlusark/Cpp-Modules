#include "../headers/Brain.hpp"

/* Default constructor */
Brain::Brain()
{
	std::cout << "Brain created by default constructor " << std::endl;
}

/* Copy constructor */
Brain::Brain(const Brain &other)
{
	std::cout << "Brain created by copy constructor " << std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
}

/* Copy assignment operator */
Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assigned by copy assignment " << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i) // array needs to be copied element by element
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

/* Destructor */
Brain::~Brain()
{
	std::cout << "Brain destroyed by destructor " << std::endl;
}