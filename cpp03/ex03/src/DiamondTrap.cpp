#include "../headers/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"), // Initialize ClapTrap's name
      ScavTrap(),                    // Call ScavTrap default constructor
      FragTrap(),                    // Call FragTrap default constructor
      name("Default")                // defualt diamond name
{
    hitPoints = FragTrap::DEFAULT_HP;    // 100
    energyPoints = ScavTrap::DEFAULT_EP; // 50
    attackDamage = FragTrap::DEFAULT_AD; // 30

    std::cout << C_PURPLE << "🤖 DiamondTrap " << C_RESET << name << " was created by parametarised constructor" << showStatus() << std::endl;
}

// speecifying constructors to avoid the compiler calls default constructor, we give name only inside claptrap init
DiamondTrap::DiamondTrap(std::string const &name)
    : ClapTrap(name + "_clap_name"), // Initialization list calls base class constructor ClapTrap with string
      ScavTrap(name),                // Same for ScavTrap with no args
      FragTrap(name),                // Same for FragTrap with no args
      name(name)                     // Initializes DiamondTrap::name with the parameter
{
    hitPoints = FragTrap::DEFAULT_HP;    // 100 (not actual needed as it's the last classes applied)
    energyPoints = ScavTrap::DEFAULT_EP; // overwrites to 50
    attackDamage = FragTrap::DEFAULT_AD; // 30 (not actual needed as it's the last classes applied)
    std::cout << C_PURPLE << "🤖 DiamondTrap " << C_RESET << name << " was created by parametarised constructor" << showStatus() << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout << C_PURPLE << "📋 DiamondTrap " << C_RESET << name << " was created by copy constructor" << showStatus() << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        name = other.name;
    }
    std::cout << C_PURPLE << "📎 DiamondTrap " << C_RESET << name << " was assigned by copy assignment" << showStatus() << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << C_PURPLE << "🪦 DiamondTrap " << C_RESET << name << " was destroyed by destructor" << showStatus() << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << C_PURPLE << "🙋  DiamondTrap" << C_RESET << " my own DiamondTrap name is " << name << " and my Claptrap name is " << ClapTrap::name << showStatus() << std::endl;
}
