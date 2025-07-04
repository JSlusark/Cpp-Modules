#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();									  // Default constructor
	WrongAnimal(const WrongAnimal &other);			  // Copy constructor
	WrongAnimal &operator=(const WrongAnimal &other); // Copy assignment operator
	~WrongAnimal();									  // Destructor
	std::string getType() const;					  // getter
	void makeSound() const;
};

#endif
