#include "../headers/DiamondTrap.hpp"

int main()
{
	DiamondTrap diamondie("Diamondie");
	diamondie.whoAmI();
	diamondie.attack("Random Bot");
	diamondie.takeDamage(20);
	diamondie.beRepaired(10);
	diamondie.guardGate();
	diamondie.highFivesGuys();
	return 0;
}
