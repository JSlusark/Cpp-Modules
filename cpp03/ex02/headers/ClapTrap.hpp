
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "colors.hpp"

class ClapTrap
{
protected: // we switch private to protected to access the attribute directly and avoid using getters and setters
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

public:
	ClapTrap(); // default constructor (does not ned params)
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);			// Copy constructor
	ClapTrap &operator=(const ClapTrap &other); // Copy assignment
	~ClapTrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string showStatus() const;
};

#endif
