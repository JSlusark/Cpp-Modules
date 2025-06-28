#include "../headers/ClapTrap.hpp"

int main()
{
	ClapTrap c1(C_CYAN "Clappie" C_RESET);

	c1.attack(C_MAGENTA "bot" C_RESET);
	c1.takeDamage(3);
	c1.beRepaired(2);
	c1.takeDamage(10);
	c1.attack(C_PURPLE "another bot" C_RESET);
	c1.beRepaired(5);
	return 0;
}
