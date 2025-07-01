#include "../headers/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"),  // Initialize ClapTrap's name
      ScavTrap(),                     // Call ScavTrap default constructor
      FragTrap(),                     // Call FragTrap default constructor
      name("Default")                   // defualt diamond name
{
    // hitPoints = FragTrap::hitPoints;       // 100
    // energyPoints = ScavTrap::energyPoints; // 50
    // attackDamage = FragTrap::attackDamage; // 30
    energyPoints = 50; // feels hardcoded

    std::cout << C_PURPLE << "🤖 DiamondTrap " << C_RESET << name << " was created by parametarised constructor" << showStatus() << std::endl;
}

// speecifying constructors to avoid the compiler calls default constructor, we give name only inside claptrap init
DiamondTrap::DiamondTrap(std::string const &name)
    : ClapTrap(name + "_clap_name"), // Initialization list calls base class constructor ClapTrap with string
      ScavTrap(name),                    // Same for ScavTrap with no args
      FragTrap(name),                    // Same for FragTrap with no args
      name(name)                     // Initializes DiamondTrap::name with the parameter
{
    // hitPoints = FragTrap::hitPoints;       // 100
    // energyPoints = ScavTrap::energyPoints; // 50
    // attackDamage = FragTrap::attackDamage; // 30
    energyPoints = 50;
    std::cout << C_PURPLE << "🤖 DiamondTrap " << C_RESET << name << " was created by parametarised constructor" << showStatus() << std::endl;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << C_PURPLE << "🪦 DiamondTrap " << C_RESET << name << " was destroyed by destructor" << showStatus() << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << C_PURPLE << "🙋  DiamondTrap" << C_RESET << " my own DiamondTrap name is " << name << " and my Claptrap name is " << ClapTrap::name << showStatus() << std::endl;
}
