
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
	// ADD COPY CONSTRUCTOR
	// ADD COPY ASSIGNMENT OPERATOR
	~ScavTrap();
	void attack(const std::string &target); // overrides claptrap attack
	void guardGate();
};

#endif
