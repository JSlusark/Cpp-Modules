#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "colors.hpp"

// Derived class (child) - the parent name is added with ":"
class FragTrap : virtual public ClapTrap
{
private: // attributes are not needed to be declared
public:
    FragTrap(); // default constructor (does not need params)
    FragTrap(const std::string &name);
    // 	// copy contructor ?
    // 	// operator constructor ?
    ~FragTrap();
    void highFivesGuys(void);
};

#endif
