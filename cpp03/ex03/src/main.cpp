#include "../headers/DiamondTrap.hpp"
#include "../headers/ScavTrap.hpp"
#include "../headers/FragTrap.hpp"
#include "../headers/ClapTrap.hpp"

int main()
{
	std::cout << "\n- Creating GrandParent A (claptrap)" << std::endl;
	ClapTrap grandParent("Grandparent_clap");

	std::cout << "\n- Creating Parent A (fragtrap)" << std::endl;
	FragTrap parentA("ParentA_frag");

	std::cout << "\n- Creating Parent B (scavtrap)" << std::endl;
	ScavTrap parentB("ParentB_scav");

	std::cout << "\n- Creating Child (diamondtrap)" << std::endl;
	DiamondTrap diamondie("child_diamond");
	
	std::cout << "\nCalling scavtrap special method on both ParentB_scav and child_diamond " << std::endl;
	parentB.guardGate();   // scavtrap special method
	diamondie.guardGate(); // scavtrap special method
	
	std::cout << "\nCalling fragtrap special method on both ParentA_frag and child_diamond " << std::endl;
	parentA.highFivesGuys();   // fragtrap special method
	diamondie.highFivesGuys(); // fragtrap special method
	
	std::cout << "\nCalling Diamondtrap special method" << std::endl;
	diamondie.whoAmI();

	std::cout << "\nCalling attack method - the closest relationship is with Scavtrap's overrid attack " << std::endl;
	diamondie.attack("Random Bot"); // scavtrap overwritten method
	
	std::cout << "\nCalling grandparent methods that were nor overrid in any parent" << std::endl;
	diamondie.takeDamage(20); // claptrap base method (as not overwritten anywhere)
	diamondie.beRepaired(10); // claptrap base method (as not overwritten anywhere)
	
	std::cout << "\nDestroying all classes by default" << std::endl;
	return 0;
}
