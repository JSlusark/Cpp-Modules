#include "../headers/ClapTrap.hpp"
#include "../headers/ScavTrap.hpp"
#include "colors.hpp"

int main()
{
	{
		ClapTrap c1(C_CYAN "Clappie" C_RESET);
		ScavTrap s1(C_YELLOW "Scavvie" C_RESET);
		s1.guardGate();
		c1.attack(C_YELLOW "Scavvie" C_RESET);
		s1.attack(C_CYAN "Clappie" C_RESET);
		c1.takeDamage(20);
		s1.attack(C_CYAN "Clappie" C_RESET);
		c1.takeDamage(20);
		c1.beRepaired(5);
		c1.attack(C_YELLOW "Scavvie" C_RESET);
	}

	{
		std::cout << "Test 1 - depleted bot" << std::endl;
		ScavTrap scav("TiredBot");

		// Drain energy
		for (int i = 0; i < 51; i++)
		{
			scav.attack("PunchBag");
		}

		scav.beRepaired(10); // ❌ Should fail — energy is 0
		scav.guardGate();	 // ✅ Should still work (no cost)
	}

	{
		std::cout << "Test 2 - copy costructor and destructor order" << std::endl;
		ScavTrap original("FirstBorn");
		ScavTrap clone = original;

		clone.attack("Target"); // ✅ Should print with clone’s name
		original.takeDamage(40);
	}

	return 0;
}
