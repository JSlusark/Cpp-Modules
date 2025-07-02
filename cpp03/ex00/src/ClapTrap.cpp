#include "../headers/ClapTrap.hpp"

std::string ClapTrap::showStatus() const
{
    std::ostringstream oss;
    oss << C_DARK_GRAY << "\nHP: " << hitPoints
        << " | EP: " << energyPoints
        << " | AD: " << attackDamage << C_RESET;

    return oss.str();
}

ClapTrap::ClapTrap() : name(C_GRAY "Default" C_RESET), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << C_CYAN << "🤖 ClapTrap " << C_RESET << name << " was created by parametarised constructor" << showStatus() << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << C_CYAN << "🤖 ClapTrap " << C_RESET << name << " was created by parametarised constructor" << showStatus() << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << C_CYAN << "📋 ClapTrap " << C_RESET << name << " was created by copy constructor" << showStatus() << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << C_CYAN << "📎 ClapTrap " << C_RESET << name << " was assigned by copy assignment" << showStatus() << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << C_CYAN << "🪦 ClapTrap " << C_RESET << name << " was destroyed by destructor" << showStatus() << std::endl;
}
void ClapTrap::attack(const std::string &target)
{
    int amount = attackDamage;
    if (hitPoints <= 0)
        std::cout << C_CYAN << "🔫😵 ClapTrap " << C_RESET << name << " is unable to attack " << target << ", it's dead!" << C_RESET << showStatus() << std::endl;
    else if (energyPoints <= 0)
        std::cout << C_CYAN << "🔫❌ ClapTrap " << C_RESET << name << " is unable to attack " << target << " and started crying, it has no energy points left! 😭" << C_RESET << showStatus() << std::endl;
    else
    {
        energyPoints--;
        std::cout << C_CYAN << "🔫 ClapTrap " << C_RESET << name << " uses 🫠WEAK_PUNCH🫠 on " << target << ", causing " << amount << " points of damage!" << C_DARK_GRAY << "(EP -1)" << showStatus() << std::endl;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
        std::cout << C_CYAN << "💦😵 ClapTrap " << C_RESET << name << " no longer can be hit, it's dead!" << C_RESET << showStatus() << std::endl;
    else
    {
        if ((int)amount <= 0) // managed unsigned int overflows like 4294967295 and negative numbers converted to positive ints
            std::cout << C_CYAN << "💦💪 ClapTrap " << C_RESET << name << " gets no damage, it was hit with an attack amount of 0 or below" << C_DARK_GRAY << " (amount:" << (int)amount << ")" << C_RESET << showStatus() << std::endl;
        else
        {
            hitPoints -= amount;
            std::cout << C_CYAN << "💦 ClapTrap " << C_RESET << name << " took " << amount << " points of damage!" << C_DARK_GRAY << "(HP -" << amount << ")" << showStatus() << std::endl;
        }
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0)
        std::cout << C_CYAN << "🪛😵 ClapTrap " << C_RESET << name << " cannot repair itself, it's dead!" << C_RESET << showStatus() << std::endl;
    else if (energyPoints <= 0)
        std::cout << C_CYAN << "🪛❌ ClapTrap " << C_RESET << name << " cannot repair itself and started crying, it has no energy points left! 😭" << C_RESET << showStatus() << std::endl;
    else
    {
        energyPoints--;
        if ((int)amount <= 0) // managed unsigned int overflows like 4294967295 and negative numbers converted to positive ints
            std::cout << C_CYAN << "🪛❌ ClapTrap " << C_RESET << name << " used energy points for a failed repair amount that is 0 or below" << C_DARK_GRAY << " (amount:" << (int)amount << ")" << C_RESET << showStatus() << std::endl;
        else
        {
            hitPoints += amount;
            std::cout << C_CYAN << "🪛 ClapTrap " << C_RESET << name << " repaired itself, gaining " << amount << " hit point(s)!" << C_DARK_GRAY << "(HP +" << amount << " | EP -1)" << showStatus() << std::endl;
        }
    }
}