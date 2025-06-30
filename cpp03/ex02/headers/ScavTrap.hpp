
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "colors.hpp"

// Derived class (child) - the parent name is added with ":"
class ScavTrap : public ClapTrap
{
private: // attributes are not needed to be declared
public:
	ScavTrap(); // default constructor (does not need params)
	ScavTrap(const std::string &name);
	// 	// copy contructor ?
	// 	// operator constructor ?
	~ScavTrap();
	void attack(const std::string &target); // overrides claptrap attack
	void guardGate();
};

#endif
