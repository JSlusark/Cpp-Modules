#include "../headers/Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"
#include "../headers/colors.hpp"

int main()
{
	{
		// const Animal *j = new Dog();
		// const Animal *i = new Cat();
		// delete j; // should not create a leak
		// delete i;
		int n = 10;
		// polymorph will not work to do half half
		// f you try to assign a Cat or Dog object into an Animal,
		// this can cause object slicing — only the Animal part is kept, the derived part is lost
		// const Animal animalArray[n];

		// a pointe needs to be used to apply runtime polymorphism
		const Animal *animalArray[n];
		for (int i = 0; i < (n / 2); i++)
		{
			std::cout << "Instantiating cat n: " << i + 1 << std::endl;
			animalArray[i] = new Cat();
			std::cout << "-" << std::endl;
		}
		for (int i = (n / 2); i < n; i++)
		{
			std::cout << "Instantiating Dog n: " << i + 1 << std::endl;
			animalArray[i] = new Dog();
			std::cout << "-" << std::endl;
		}

		// massdelete
		for (int i = 0; i < n; i++)
		{
			std::cout << "Destroying animal n: " << i + 1 << std::endl;
			delete animalArray[i]; // check diff with zombie delete, why not delete[];
			std::cout << "-" << std::endl;
		}
	}

	std::cout << "Creating base Dog...\n";
	Dog basic;

	std::cout << "\nCreating a copy in a new scope...\n";
	{
		Dog tmp = basic; // This calls the copy constructor
		std::cout << "Exiting scope, tmp will be destroyed...\n";
	}
	std::cout << "\nIf we reach this message without a crash, copy constructor worked smoothly...\n";
	
	std::cout << "\nAssigning basic dog to a temp...\n";
	{
		Dog tmp; // This calls the copy constructor
		tmp = basic; // This calls the assignment operator
		std::cout << "Exiting scope, tmp will be destroyed...\n";
	}
	std::cout << "\nIf we reach this message without a crash, copy assignment worked smoothly...\n";

	// Optional: Access Brain content to be sure
	// basic.setIdea(0, "Original");
	// std::cout << "Idea 0 of basic: " << basic.getIdea(0) << std::endl;

	// {
	// 	Cat original;
	// 	Cat copy(original);

	// 	std::cout << "Modifying copy's brain idea 0...\n";
	// 	copy.setIdea(0, "I'm a copy");

	// 	std::cout << "Original brain idea 0: " << original.getIdea(0) << "\n";
	// 	std::cout << "Copy brain idea 0:     " << copy.getIdea(0) << "\n";
	// 	// Expect different values → proves deep copy
	// }
	// {
	// 	std::cout << C_YELLOW << "\n------ RIGHT POLYMORPHIC TEST --------\n"
	// 			  << C_RESET << std::endl;
	// 	const Animal *animal_obj = new Animal();
	// 	std::cout << "-" << std::endl;
	// 	const Animal *dog_obj = new Dog();
	// 	std::cout << "-" << std::endl;
	// 	const Animal *cat_obj = new Cat();
	// 	std::cout << "-" << std::endl;
	// 	//  Makesound is called properly because ~Animal is virtual
	// 	std::cout << "Type of cat_obj is: " << cat_obj->getType() << std::endl;
	// 	std::cout << "cat_obj goes: ";
	// 	cat_obj->makeSound();
	// 	std::cout << "-" << std::endl;
	// 	std::cout << "Type of dog_obj is: " << dog_obj->getType() << std::endl;
	// 	std::cout << "dog_obj goes: ";
	// 	dog_obj->makeSound(); // dog function overrides animal function
	// 	std::cout << "-" << std::endl;
	// 	std::cout << "animal_obj goes: ";
	// 	animal_obj->makeSound(); // cat function overrides animal function
	// 	//  All destructors called properly because ~Animal is virtual
	// 	std::cout << "-" << std::endl;
	// 	delete animal_obj;
	// 	std::cout << "-" << std::endl;
	// 	delete dog_obj;
	// 	std::cout << "-" << std::endl;
	// 	delete cat_obj;
	// }
	// {
	// 	std::cout << C_YELLOW << "\n------ WRONG POLYMORPHYC TEST--------\n"
	// 			  << C_RESET << std::endl;
	// 	const WrongAnimal *wrongAnimal = new WrongAnimal();
	// 	std::cout << "-" << std::endl;
	// 	const WrongAnimal *wrongCat = new WrongCat();
	// 	std::cout << "-" << std::endl;
	// 	//  Makesound is NOT called properly because ~Animal is virtual
	// 	std::cout << "Type of wrongAnimal is: " << wrongAnimal->getType() << std::endl;
	// 	std::cout << "wrongAnimal goes: ";
	// 	wrongAnimal->makeSound();
	// 	std::cout << "-" << std::endl;
	// 	std::cout << "Type of wrongCat is: " << wrongCat->getType() << std::endl;
	// 	std::cout << "wrongCat goes:  ";
	// 	wrongCat->makeSound(); // does not do wrong catsound as base class overridden function is not virtual
	// 	std::cout << "-" << std::endl;
	// 	delete wrongCat; // wrongCat class does not get destroyed because wrongAnimal has no virtual destruction
	// 	std::cout << "-" << std::endl;
	// 	delete wrongAnimal;
	// }
	// {
	// 	std::cout << C_YELLOW << "\n------ RIGHT WRONGCAT TEST (non-polymorphic, derived class hides base class, does not override) --------\n"
	// 			  << C_RESET << std::endl;
	// 	//
	// 	WrongCat trueWrongCat;
	// 	trueWrongCat.makeSound(); // WrongCat sound works as we created static objects
	// 							  // WrongCat gets also desturucted right as the absence of virtual in base class does not affect destruction in this case
	// }

	return 0;
}