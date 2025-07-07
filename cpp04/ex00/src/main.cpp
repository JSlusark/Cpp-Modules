#include "../headers/Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"
#include "colors.hpp"

int main()
{
	{
		std::cout << C_YELLOW << "\n------ RIGHT POLYMORPHIC TEST --------\n"
				  << C_RESET << std::endl;
		const Animal *animal_obj = new Animal();
		std::cout << "-" << std::endl;
		const Animal *dog_obj = new Dog();
		std::cout << "-" << std::endl;
		const Animal *cat_obj = new Cat();
		std::cout << "-" << std::endl;
		//  Makesound is called properly because ~Animal is virtual
		std::cout << "Type of cat_obj is: " << cat_obj->getType() << std::endl;
		std::cout << "cat_obj goes: ";
		cat_obj->makeSound();
		std::cout << "-" << std::endl;
		std::cout << "Type of dog_obj is: " << dog_obj->getType() << std::endl;
		std::cout << "dog_obj goes: ";
		dog_obj->makeSound(); // dog function overrides animal function
		std::cout << "-" << std::endl;
		std::cout << "animal_obj goes: ";
		animal_obj->makeSound(); // cat function overrides animal function
		//  All destructors called properly because ~Animal is virtual
		std::cout << "-" << std::endl;
		delete animal_obj;
		std::cout << "-" << std::endl;
		delete dog_obj;
		std::cout << "-" << std::endl;
		delete cat_obj;
	}
	{
		std::cout << C_YELLOW << "\n------ WRONG POLYMORPHYC TEST--------\n"
				  << C_RESET << std::endl;
		const WrongAnimal *wrongAnimal = new WrongAnimal();
		std::cout << "-" << std::endl;
		const WrongAnimal *wrongCat = new WrongCat();
		std::cout << "-" << std::endl;
		//  Makesound is NOT called properly because ~Animal is virtual
		std::cout << "Type of wrongAnimal is: " << wrongAnimal->getType() << std::endl;
		std::cout << "wrongAnimal goes: ";
		wrongAnimal->makeSound();
		std::cout << "-" << std::endl;
		std::cout << "Type of wrongCat is: " << wrongCat->getType() << std::endl;
		std::cout << "wrongCat goes:  ";
		wrongCat->makeSound(); // does not do wrong catsound as base class overridden function is not virtual
		std::cout << "-" << std::endl;
		delete wrongCat; // wrongCat class does not get destroyed because wrongAnimal has no virtual destruction
		std::cout << "-" << std::endl;
		delete wrongAnimal;
	}
	{
		std::cout << C_YELLOW << "\n------ RIGHT WRONGCAT TEST (non-polymorphic, derived class hides base class, does not override) --------\n"
				  << C_RESET << std::endl;
		// 
		WrongCat trueWrongCat;
		trueWrongCat.makeSound(); // WrongCat sound works as we created static objects
								  // WrongCat gets also desturucted right as the absence of virtual in base class does not affect destruction in this case
	}

	return 0;
}