
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "colors.hpp"

class ScavTrap : public ClapTrap
{
private: // attributes are not needed to be declared
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);			// Copy constructor
	ScavTrap &operator=(const ScavTrap &other); // Copy assignment
	~ScavTrap();
	void attack(const std::string &target); // overrides claptrap attack
	void guardGate();
};

#endif
