#include "../headers/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default") // default constructor
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "🤖 ScavTrap " << name << " was created by parametarised constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) // parametarised constructor
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "🤖 ScavTrap " << name << " was created by parametarised constructor" << std::endl;
}
ScavTrap::~ScavTrap()
{
    std::cout << "🪦 ScavTrap " << name << " was destroyed by destructor" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "🗝️ ScavTrap " << name << " is in GateKeeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    int amount = attackDamage;
    if (energyPoints <= 0 || hitPoints <= 0) // put <=  in case it goes below 0
        std::cout << C_RED << "🔫 ScavTrap " << name << C_RED << " cannot attack " << target << C_RED << " becayse energy and hitpoints are depleted 🪫" << C_RESET << std::endl;
    else
    {
        std::cout << "🔫 ScavTrap " << name << " uses 👋💥SLAP💥👋 " << target << ", causing " << amount << " points of damage!" << std::endl;
        energyPoints--;
    }
}