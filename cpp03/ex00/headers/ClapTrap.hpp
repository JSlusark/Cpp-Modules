
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

#define C_RESET "\033[0m"
#define C_GREEN "\033[38;2;0;255;128m"
#define C_YELLOW "\033[38;2;255;255;0m"
#define C_RED "\033[38;2;255;85;85m"
#define C_MAGENTA "\033[38;2;255;0;255m"
#define C_PURPLE "\033[38;2;180;0;255m"
#define C_CYAN "\033[38;2;0;255;255m"
#define C_GRAY "\033[38;2;150;150;150m"

class ClapTrap
{
private:
	std::string name;
	int hitPoints; // I think they were meant to write health points (HP🤦‍♀️)
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
