#include "../headers/Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"
#include "../headers/colors.hpp"

int main()
{
	/*
		{
			std::cout << C_YELLOW << "\n------ Instantiation of Animal class (compiler fails) ------" << C_RESET << std::endl;
			Animal a;				  // animal is abstract, polymorphism does not occur as no object is created do to compile err
			Animal *b = new Animal(); // animal is abstract, polymorphism does not occur as no object is created do to compile err
		}
	*/

	{
		std::cout << C_YELLOW << "\n------ Stack allocation of derived classes ------" << C_RESET << std::endl;
		Dog dog;
		Cat cat;
		dog.makeSound();
		cat.makeSound(); // if i remove the overriden cat function cat should become abstract too and init cat will fail
						 // destructor called automatically as it's stack allocation
	}

	// the only way to use Animal class name is to create an animal pointer that points to a derived class member (upcasting)
	{
		std::cout << C_YELLOW << "\n------ Upcasting to abstract base class pointer ------" << C_RESET << std::endl;
		Animal *dog = new Dog(); // this is called upcasting
		Animal *cat = new Cat();
		dog->makeSound();
		cat->makeSound(); // if i remove the overriden cat function cat should become abstract too and init cat will fail
		delete dog;
		delete cat;
	}

	std::cout << C_YELLOW << "\n------ Polymorphic array using base class pointers ------" << C_RESET << std::endl;
	// upcasting  allows flexibility, in this case we can initialise different derived class through a common interface / base class
	Animal *zoo[2] = {new Dog(), new Cat()}; // this is not possible by using a dog or cat array directly for example
	for (int i = 0; i < 2; i++)
	{
		zoo[i]->makeSound(); // derived classshould override the pure virtual fuction of base class
		delete zoo[i];
	}

	{
		// when this is useful, when you know the baseclass but not he actual class of an object
		std::cout << C_YELLOW << "\n------ Upcasting on runtime value (polymorphism) based on conditionals ------" << C_RESET << std::endl;
		Animal *animal = NULL;
		std::string input = "cat";
		std::cout << C_CYAN << "Input left from user is: " << input << C_RESET << std::endl;
		if (input == "dog")
			animal = new Dog();
		else if (input == "cat")
			animal = new Cat();
		animal->makeSound(); // works only if virtual
		delete animal;
	}

	{
		std::cout << C_YELLOW << "\n------ Reassigning base pointer (be careful with memory leaks!) ------" << C_RESET << std::endl;
		Animal *change_assignment = new Dog();
		delete change_assignment;
		change_assignment = new Cat();
		delete change_assignment; // clean up again
	}

	{
		// invalid copy costructor
		std::cout << C_YELLOW << "\n------ Invalid assignment between different derived classes - causes undefined behaviour ------" << C_RESET << std::endl;
		Animal *a = new Dog();
		Animal *b = new Cat();
		*a = *b; // ❌ Invalid — object slicing(copies only the animal part with its copy) + incompatible types!
	}
	{
		std::cout << C_YELLOW << "\n------ Valid copy assignment (same derived type) ------" << C_RESET << std::endl;
		// valid copy costructor (only with the same derived class, no slicing, both base and dervied copy constructor called)
		Dog basicDog;
		Dog copyDog = basicDog; // calls Dog's copy constructor

		// valid copy assignment
		Cat cat1;
		Cat cat2;
		cat2 = cat1; // Copy assignment of same type
	}

	return 0;
}