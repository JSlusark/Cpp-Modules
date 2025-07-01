
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip> // for std::setw and std::right
#include "colors.hpp"

#define C_RESET "\033[0m"
#define C_GREEN "\033[38;2;0;255;128m"
#define C_YELLOW "\033[38;2;255;255;0m"
#define C_RED "\033[38;2;255;85;85m"
#define C_MAGENTA "\033[38;2;255;0;255m"
#define C_PURPLE "\033[38;2;180;0;255m"
#define C_CYAN "\033[38;2;0;255;255m"
#define C_DARK_GRAY "\033[38;5;240m"

// base class (parent)
class ClapTrap
{
private:
	std::string name;
	int hitPoints; // I think they were meant to write health points (HP🤦‍♀️)
	int energyPoints;
	int attackDamage;

public:
	ClapTrap(); // default constructor (does not ned params)
	ClapTrap(const std::string &name); // parametarised constructor
	// ADD COPY CONSTRUCTOR
	// ADD COPY ASSIGNMENT OPERATOR
	~ClapTrap(); // destructor
	void attack(const std::string &target); // - 1 energyPoint, damages with amount, cannot happen when hitPoints and energyPoints = 0
	void takeDamage(unsigned int amount); // hp - amount
	void beRepaired(unsigned int amount); // - 1 energyPoint hp + amount, cannot happen when hitPoints and energyPoints = 0
	std::string showStatus() const;
};

#endif
