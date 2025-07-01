#include "../headers/ClapTrap.hpp"
#include "../headers/ScavTrap.hpp"
#include "colors.hpp"

int main()
{
	{
		std::cout << "\nTest 0 - Clappie and Scavvie fight" << std::endl;
		ClapTrap clappie("Clappie");
		ScavTrap scavvie("Scavvie");
		scavvie.guardGate();
		clappie.attack("Scavvie");
		scavvie.beRepaired(100);
		scavvie.attack("Clappie");
		clappie.takeDamage(20);
		scavvie.attack("Clappie");
		clappie.takeDamage(20);
		clappie.beRepaired(5);
		clappie.attack("Scavvie");
		std::cout << "\nScavvie is attacked by a random god level machine with 1000 attack hit points!!!!" << std::endl;
		scavvie.takeDamage(1000); // se if need to have limit
	}

	{
		std::cout << "\n Test 1 - depleted bot" << std::endl;
		ScavTrap scavvie("Scavvie");

		// Drain energy
		for (int i = 0; i < 51; i++)
		{
			scavvie.attack("PunchBag");
		}

		scavvie.beRepaired(10); // Should fail as energy is 0
		scavvie.guardGate();	// Should still work as no cost needed
	}

	{
		std::cout << "\n Test 2 - Dead bot tries guard mode" << std::endl;
		ScavTrap scavvie("Scavvie");
		scavvie.takeDamage(1000);
		scavvie.guardGate(); // Should still work as dead as no conditions added
	}

	{
		std::cout << "\n Test 3 - Repair chain" << std::endl;
		ScavTrap scavvie("Scavvie");

		for (int i = 0; i < 51; i++)
			scavvie.beRepaired(1); // Should repair 50 times then fail on 51
		scavvie.attack("PunchBag");
	}

	{
		std::cout << "\n Test 3 - Repair chain" << std::endl;
		ScavTrap scavvie("Scavvie");
		scavvie.takeDamage(1000);
		scavvie.beRepaired(1200); // Should repair 50 times then fail on 51
		scavvie.attack("Random Bot");
		scavvie.takeDamage(2000);
	}

	return 0;
}
