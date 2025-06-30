#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP
#include <string>
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "colors.hpp"

// Derived class (child) - the parent name is added with ":"
class DiamondTrap : public ScavTrap, public FragTrap
{
private: // attributes are not needed to be declared
    std::string name;

public:
    DiamondTrap(); // default constructor (does not need params)
    DiamondTrap(const std::string &name);
    // 	// copy contructor ?
    // 	// operator constructor ?
    ~DiamondTrap();
    using ScavTrap::attack; // ScavTrap's attack method - it still uses it if not specifed.. is it because it relies on parent before grandparent? (as fragtrap does not have attack)
    void whoAmI(void);
};

#endif
