#include "../headers/Animal.hpp"
#include "../headers/Cat.hpp"
#include "../headers/Dog.hpp"
#include "../headers/WrongAnimal.hpp"
#include "../headers/WrongCat.hpp"

int main()
{
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();
	}
	{
		std::cout << "------ NORMAL ANIMALS --------" << std::endl;

		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << "j->getType(): " << j->getType() << std::endl;
		std::cout << "i->getType(): " << i->getType() << std::endl;

		std::cout << "i->makeSound(): ";
		i->makeSound(); // Cat sound

		std::cout << "j->makeSound(): ";
		j->makeSound(); // Dog sound

		std::cout << "meta->makeSound(): ";
		meta->makeSound(); // Animal sound

		delete meta;
		delete j;
		delete i;

		std::cout << std::endl;
	}
	{
		std::cout << "------ WRONG ANIMALS --------" << std::endl;

		const WrongAnimal *wrong = new WrongAnimal();
		const WrongAnimal *wrongCat = new WrongCat();

		std::cout << "wrongCat->getType(): " << wrongCat->getType() << std::endl;

		std::cout << "wrong->makeSound(): ";
		wrong->makeSound(); // WrongAnimal sound

		std::cout << "wrongCat->makeSound(): ";
		wrongCat->makeSound(); // Still WrongAnimal sound (no virtual)

		delete wrong;
		delete wrongCat;

		std::cout << std::endl;
	}
	{
		std::cout << "------ DIRECT WRONGCAT TEST --------" << std::endl;

		WrongCat trueWrongCat;
		trueWrongCat.makeSound(); // ✅ WrongCat sound (works only directly)
	}

	return 0;
}