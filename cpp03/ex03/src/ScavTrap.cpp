#include "../headers/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default") // default constructor
{
    hitPoints = DEFAULT_HP;
    energyPoints = DEFAULT_EP;
    attackDamage = DEFAULT_AD;
    std::cout << C_YELLOW << "🤖 ScavTrap " << C_RESET << name << " was created by parametarised constructor" << showStatus() << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) // parametarised constructor
{
    hitPoints = DEFAULT_HP;
    energyPoints = DEFAULT_EP;
    attackDamage = DEFAULT_AD;
    std::cout << C_YELLOW << "🤖 ScavTrap " << C_RESET << name << " was created by parametarised constructor" << showStatus() << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) // Call base class copy constructor
{
    std::cout << C_YELLOW << "📋 ScavTrap " << C_RESET << name << " was created by copy constructor" << showStatus() << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other); // Call base class assignment operator
        // No extra attributes to assign here
    }
    std::cout << C_YELLOW << "📎 ScavTrap " << C_RESET << name << " was assigned by copy assignment" << showStatus() << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << C_YELLOW << "🪦 ScavTrap " << C_RESET << name << " was destroyed by destructor" << showStatus() << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << C_YELLOW << "🗝️  ScavTrap " << C_RESET << name << " is in GateKeeper mode" << showStatus() << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    int amount = attackDamage;
    if (hitPoints <= 0)
        std::cout << C_YELLOW << "🔫😵 ScavTrap " << C_RESET << name << " cannot attack " << target << ", it's dead!" << C_RESET << showStatus() << std::endl;
    else if (energyPoints <= 0)
        std::cout << C_YELLOW << "🔫❌ ScavTrap " << C_RESET << name << " cannot attack " << target << ", it got angry for its energy points depletion" << C_RESET << showStatus() << std::endl;
    else
    {
        energyPoints--;
        std::cout << C_YELLOW << "🔫 ScavTrap " << C_RESET << name << " uses 👋SLAP👋 on " << target << ", causing " << amount << " points of damage!" << C_DARK_GRAY << "(EP -1)" << showStatus() << std::endl;
    }
}