#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "colors.hpp"

class FragTrap : public ClapTrap
{
private: // attributes are not needed to be redeclared
public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);            // Copy constructor
    FragTrap &operator=(const FragTrap &other); // Copy assignment operator
    ~FragTrap();
    void highFivesGuys(void);
};

#endif
