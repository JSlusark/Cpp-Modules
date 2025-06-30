#include "../headers/ClapTrap.hpp"
#include "../headers/ScavTrap.hpp"
#include "colors.hpp"

int main()
{
	{
		std::cout << "\nTest 0 - Clappie and Scavvie fight" << std::endl;
		ClapTrap c1("Clappie");
		ScavTrap s1("Scavvie");
		s1.guardGate();
		c1.attack("Scavvie");
		s1.beRepaired(100);
		s1.attack("Clappie");
		c1.takeDamage(20);
		s1.attack("Clappie");
		c1.takeDamage(20);
		c1.beRepaired(5);
		c1.attack("Scavvie");
		std::cout << "Scavvie is attacked by random god level machine with 1000 attack hit points!!!!" << std::endl;
		s1.takeDamage(1000); // se if need to have limit
	}

	{
		std::cout << "\n Test 1 - depleted bot" << std::endl;
		ScavTrap scav("TiredBot");

		// Drain energy
		for (int i = 0; i < 51; i++)
		{
			scav.attack("PunchBag");
		}

		scav.beRepaired(10); // Should fail as energy is 0
		scav.guardGate();	 // Should still work as no cost needed
	}

	{
		std::cout << "\n Test 2 - Dead bot tries guard mode" << std::endl;
		ScavTrap dead("Ghost");
		dead.takeDamage(1000);
		dead.guardGate(); // Should still work as dead as no conditions added
	}

	{
		std::cout << "\n Test 3 - Repair chain" << std::endl;
		ScavTrap repairBot("FixIt");

		for (int i = 0; i < 51; i++)
			repairBot.beRepaired(1); // Should repair 50 times then fail on 51
		repairBot.attack("PunchBag");
	}

	{
		std::cout << "\n Test 3 - Repair chain" << std::endl;
		ScavTrap defeatBot("FixIt");
		defeatBot.takeDamage(1000);
		defeatBot.beRepaired(1200); // Should repair 50 times then fail on 51
		defeatBot.attack("winnerBot");
		defeatBot.takeDamage(2000);
	}


	return 0;
}
