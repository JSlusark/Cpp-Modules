#include "../headers/DiamondTrap.hpp"
#include "../headers/ScavTrap.hpp"
#include "../headers/FragTrap.hpp"
#include "../headers/ClapTrap.hpp"

int main()
{
	ClapTrap grandParent("Grandparent_clap");
	FragTrap parentA("ParentA_frag");
	ScavTrap parentB("ParentB_scav");
	DiamondTrap diamondie("child_diamond");
	diamondie.whoAmI();
	diamondie.attack("Random Bot");
	diamondie.takeDamage(20);
	diamondie.beRepaired(10);
	diamondie.guardGate();
	diamondie.highFivesGuys();
	return 0;
}
