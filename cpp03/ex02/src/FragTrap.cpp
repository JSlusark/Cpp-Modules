#include "../headers/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default") // default constructor
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << C_GREEN << "🤖 FragTrap " << C_RESET << name << " was created by parametarised constructor" << showStatus() << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) // parametarised constructor
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << C_GREEN << "🤖 FragTrap " << C_RESET << name << " was created by parametarised constructor" << showStatus() << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << C_GREEN << "🪦 FragTrap " << C_RESET << name << " was destroyed by destructor" << showStatus() << std::endl;
}

void FragTrap::highFivesGuys(void){
    std::cout << C_GREEN << "🖐️ FragTrap " << C_RESET << name << " is requesting a high five to everyone in the room!" << showStatus() << std::endl;
}
