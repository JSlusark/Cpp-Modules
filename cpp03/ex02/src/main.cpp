#include "../headers/ClapTrap.hpp"
#include "../headers/FragTrap.hpp"
#include "../headers/ScavTrap.hpp"
#include "colors.hpp"

int main()
{

	{
		std::cout << "\n Test 0 - all 3 classes" << std::endl;
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
		clappie.takeDamage(100);// has base attack phrase
	}

	{
		std::cout << "\n Test 1 - depleted bot" << std::endl;
		FragTrap scav("TiredBot");

		// Drain energy
		for (int i = 0; i < 51; i++)
		{
			scav.attack("PunchBag");
		}

		scav.beRepaired(10); // Should fail as energy is 0
	}

	{
		std::cout << "\n Test 2 - Dead bot tries guard mode" << std::endl;
		FragTrap dead("Ghost");
		dead.takeDamage(1000);
	}

	{
		std::cout << "\n Test 3 - Repair chain" << std::endl;
		FragTrap repairBot("FixIt");

		for (int i = 0; i < 51; i++)
			repairBot.beRepaired(1); // Should repair 50 times then fail on 51
		repairBot.attack("PunchBag");
	}

	{
		std::cout << "\n Test 3 - Repair chain" << std::endl;
		FragTrap defeatBot("FixIt");
		defeatBot.takeDamage(1000);
		defeatBot.beRepaired(1200); // Should repair 50 times then fail on 51
		defeatBot.attack("winnerBot");
		defeatBot.takeDamage(2000);
	}


	return 0;
}
