#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
private:
public:
	Cat();							  // Default constructor
	Cat(const Cat &other);			  // Copy constructor
	Cat &operator=(const Cat &other); // Copy assignment operator
	~Cat();							  // Destructor
	void makeSound() const;
};

#endif
