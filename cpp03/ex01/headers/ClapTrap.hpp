
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>
#include "colors.hpp"

// base class (parent)
class ClapTrap
{
protected: // we switch private to protected to access the attribute directly and avoid using getters and setters
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

public:
	ClapTrap(); // default constructor (does not ned params)
	ClapTrap(std::string name);
	// copy contructor ?
	// operator constructor ?
	~ClapTrap();
	void attack(const std::string &target); // costs 1 energyPoint, cannot happen when hitPoints and energyPoints = 0
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount); // costs 1 energyPoint, cannot happen when hitPoints and energyPoints = 0
};

#endif
