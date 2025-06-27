#include "../headers/ClapTrap.hpp"

ClapTrap::ClapTrap() {}
ClapTrap::ClapTrap(std::string name) : name(name) {}

ClapTrap::~ClapTrap() {}
void ClapTrap::attack(const std::string &target)
{
    /*
    ATTACK_DAMAGE +1 to target
    ENERGY_POINTS -1
    --------------------
    if ENERGY_POINTS or HIT_POINTS are 0 canot do attack

    */
    if (!ENERGY_POINTS || !HIT_POINTS)
    {
        std::cout << "ClapTrap "  cannot attack " << target << " because energy points or hit points are 0" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " attacks" << target << ", causing " << target << " " << amount << " points of damage!" << std::endl;
        ENERGY_POINTS - 1; 
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    /*
    if ENERGY_POINTS or HIT_POINTS are 0 cannot take damage either?
    attack damage + amount
    */

    std::cout << "ClapTrap " << name << " took" << amount << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    /*
    HIT_POINTS + amout
    ENERGY_POINTS - 1
    if ENERGY_POINTS or HIT_POINTS are 0 canot do repair
    */
    std::cout << "ClapTrap " << name << " repaired itself, using" << amount << "energy point!" << std::endl;
}