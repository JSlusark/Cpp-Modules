#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "colors.hpp"
#include <iostream>
#include <string>


/* 
	Exercise asks to change the class so that animal cannot be instantiated on both the stack or the heap:
	Animal a;
	Animal *b = new Animal(); 

	To do so we need to make the class abstract by declaring at least one pure virtual function.

	 - what does abstarct mean and why is it used?
	 - is just declaring 1 function as pure virtual enough or the only way to make a clas abstract?
	 - what is a pure virtual function? what does it do? do we use it also in other cases?

	We can still derive from the Animal class (e.g., Dog, Cat) and instantiate those subclasses -> as long as they override all pure virtual functions.
	 - What happens if that function is not overridden in the derived classes?
	 - Are there other ways or is this the only way? Just to know
	 
*/

class Animal
{
private:
protected:
	std::string type;

public:
	Animal();								
	Animal(const Animal &other);			
	Animal &operator=(const Animal &other); 
	virtual ~Animal();						
	std::string getType() const;			
	virtual void makeSound() const = 0;		// pure virtual function makes the class non instantiable
};

#endif
