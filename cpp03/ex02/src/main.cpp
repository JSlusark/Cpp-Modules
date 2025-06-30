#include "../headers/ClapTrap.hpp"
#include "../headers/FragTrap.hpp"
#include "../headers/ScavTrap.hpp"
#include "colors.hpp"

int main()
{

	{
		std::cout << "\n Test 0 - all 3 classes interact" << std::endl;
		ClapTrap clappie("Clappie");
		ScavTrap scavvie("Scavvie");
		FragTrap fraggie("Fraggie");

		fraggie.highFivesGuys();
		scavvie.guardGate();
		clappie.attack("Scavvie"); // has base attack phrase
		scavvie.takeDamage(0); // has base takedamage phrase
		fraggie.takeDamage(100);
		fraggie.beRepaired(100); // has base repair phrase
		fraggie.attack("Clappie"); // has base repair phrase
		scavvie.attack("Clappie"); // has own attack phrase
		clappie.takeDamage(20);// has base attack phrase
		clappie.attack("Scavvie");// has base attack phrase
	}

	{
		std::cout << "\n Test 1 - all 3 classes are constructed / destructed" << std::endl;
		ClapTrap clappie("Clappie");
		ScavTrap scavvie("Scavvie");
		FragTrap fraggie("Fraggie");
	}
	
	return 0;
}
