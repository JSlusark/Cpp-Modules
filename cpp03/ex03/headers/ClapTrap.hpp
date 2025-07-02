
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip> // for std::setw and std::right
#include "colors.hpp"

class ClapTrap
{
protected:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);			// Copy constructor
	ClapTrap &operator=(const ClapTrap &other); // Copy assignment
	virtual ~ClapTrap();						// added virtual to safely call the correct derived destructors when a derived object is deleted via a base pointer
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string showStatus() const;
};

#endif
