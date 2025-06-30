#include "../headers/ClapTrap.hpp"

void printStatus(std::string name, int hitPoints, int energyPoints, int attackDamage)
{
    std::string hpColor;
    if (hitPoints <= 0)
        hpColor = C_RED;
    else
        hpColor = C_GREEN;
    std::string epColor;
    if (energyPoints <= 0)
        epColor = C_RED;
    else
        epColor = C_GREEN;
    std::string adColor;
    if (attackDamage <= 0)
        adColor = C_RED;
    else
        adColor = C_GREEN;

    std::cout << "            " << name << ":    Hit Points: " << hpColor << hitPoints << C_RESET << "/10 | " << "Energy Points: " << epColor << energyPoints << C_RESET << "/10 | " << "Attack Damage: " << adColor << attackDamage << C_RESET << std::endl;
}

ClapTrap::ClapTrap() : name(C_GRAY "Default" C_RESET), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "🤖 ClapTrap " << name << " was created by parametarised constructor" << std::endl;
    printStatus(name, hitPoints, energyPoints, attackDamage);
}
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "🤖 ClapTrap " << name << " was created by parametarised constructor" << std::endl;
    printStatus(name, hitPoints, energyPoints, attackDamage);
}

ClapTrap::~ClapTrap()
{
    std::cout << "🪦 ClapTrap " << name << " was destroyed by destructor" << std::endl;
}
void ClapTrap::attack(const std::string &target)
{
    /*
    ATTACK_DAMAGE +1 to target
    energyPoints -1
    --------------------
    if energyPoints or hitPoints are 0 canot do attack

    */
    int amount = attackDamage;
    if (energyPoints <= 0 || hitPoints <= 0) // put <=  in case it goes below 0
        std::cout << C_RED << "🔫 ClapTrap " << name << C_RED << " is unable to attack " << target << C_RED << " and started crying as their energy points or hit points are 0 😭" << C_RESET << std::endl;
    else
    {
        std::cout << "🔫 ClapTrap " << name << " uses TRIPLE_PUNCH 🥊🥊🥊 on" << target << ", causing " << amount << " points of damage!" << std::endl;
        energyPoints--;
    }
    printStatus(name, hitPoints, energyPoints, attackDamage);
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount <= 0)
        std::cout << "❌ ClapTrap " << name << C_RED << " receives no damages as attack was of amount 0 or below" << C_RESET << std::endl;
    else if (hitPoints <= 0)
        std::cout << "💦 ClapTrap " << name << C_RED << " hit points are depleted!" << C_RESET << std::endl;
    else
        std::cout << "💦 ClapTrap " << name << " took " << amount << " points of damage!" << std::endl;
    hitPoints -= amount;
    printStatus(name, hitPoints, energyPoints, attackDamage);
}
void ClapTrap::beRepaired(unsigned int amount)
{
    /*
    hitPoints + amout
    energyPoints - 1
    if energyPoints or hitPoints are 0 canot do repair
    */
    if (energyPoints <= 0 || hitPoints <= 0) // put <=  in case it goes below 0
        std::cout << C_RED << "🪫 ClapTrap " << name << C_RED << " cannot repair itself because energy points or hit points are 0" << C_RESET << std::endl;
    else
    {
        std::cout << "🪛 ClapTrap " << name << " repaired itself, using " << amount << " energy point!" << std::endl;
        energyPoints--;
        hitPoints += amount;
    }
    printStatus(name, hitPoints, energyPoints, attackDamage);
}