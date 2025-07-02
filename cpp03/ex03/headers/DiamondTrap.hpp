#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP
#include <string>
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "colors.hpp"

class DiamondTrap : public ScavTrap, public FragTrap // double inheritance
{
private:
    std::string name;

public:
    DiamondTrap();
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &other);            // Copy constructor
    DiamondTrap &operator=(const DiamondTrap &other); // Copy assignment operator
    ~DiamondTrap();
    using ScavTrap::attack; // 'using' deals with method ambiguity, used to unhide inherited overloaded functions
    void whoAmI(void);      // to show how identity works
};

#endif
