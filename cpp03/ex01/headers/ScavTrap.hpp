
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "colors.hpp"

class ScavTrap : public ClapTrap
{
private: // attributes are not needed to be re-declared
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	// ADD COPY CONSTRUCTOR
	// ADD COPY ASSIGNMENT OPERATOR
	~ScavTrap();
	void attack(const std::string &target);
	void guardGate();
	// 	takeDamage is inherited
	// beRepaired is inherited
};

#endif
