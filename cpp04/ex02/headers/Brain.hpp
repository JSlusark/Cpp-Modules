#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <iostream>

class Brain
{
private:
	std::string ideas[100]; // dog and cat will have a private brain attribute

public:
	Brain();							  // Default constructor
	Brain(const Brain &other);			  // Copy constructor
	Brain &operator=(const Brain &other); // Copy assignment operator
	~Brain();							  // Destructor
};

#endif
