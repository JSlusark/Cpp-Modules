#include "../headers/ClapTrap.hpp"

ClapTrap::ClapTrap() {}
ClapTrap::ClapTrap(std::string name) : name(name) {}

ClapTrap::~ClapTrap() {}
void ClapTrap::attack(const std::string &target)
{
    /*
    causes damage to target
    decreases energy point by 1
    */
    std::cout << "ClapTrap " << name << " attacks" << target << ", causing " << target << " " << amount << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " took" << amount << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    /*
    increases energy point by 1
    decreases energy point by 1
    */
    std::cout << "ClapTrap " << name << " repaired itself, using" << amount << "energy point!" << std::endl;
}