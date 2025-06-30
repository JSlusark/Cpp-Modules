#include "../headers/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_Clap_Name"), name("default") // default constructor
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << C_PURPLE << "🤖 DiamondTrap " << C_RESET << name << " was created by parametarised constructor" << showStatus() << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), name(name) // <------- check if i can pass the actual clap name
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << C_PURPLE << "🤖 DiamondTrap " << C_RESET << name << " was created by parametarised constructor" << showStatus() << std::endl;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << C_PURPLE << "🪦 DiamondTrap " << C_RESET << name << " was destroyed by destructor" << showStatus() << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << C_PURPLE << "🖐️  DiamondTrap" << C_RESET << " own name is " << name << " and Claptrap name is " << ClapTrap::name << showStatus() << std::endl;
}
