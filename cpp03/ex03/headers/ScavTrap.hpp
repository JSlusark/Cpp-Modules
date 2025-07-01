
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "colors.hpp"

class ScavTrap : virtual public ClapTrap // virtual creates one shared copy between frag and scav trap, to avoid duplication in case another class inherits from them
{
private:
    // std::string name;
    // int hitPoints;
    // int energyPoints;
    // int attackDamage;
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	~ScavTrap();
	void attack(const std::string &target);
	void guardGate();
};

#endif
