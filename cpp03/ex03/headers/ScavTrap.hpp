
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "colors.hpp"

class ScavTrap : virtual public ClapTrap // virtual creates one shared copy between frag and scav trap, to avoid duplication in case another class inherits from them
{
private:
protected:
	static const int DEFAULT_HP = 100; // used this as assigning into the constructor will just assign to object and not class
	static const int DEFAULT_EP = 50;  // used this as assigning into the constructor will just assign to object and not class
	static const int DEFAULT_AD = 20;  // used this as assigning into the constructor will just assign to object and not class
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);			// Copy constructor
	ScavTrap &operator=(const ScavTrap &other); // Copy assignment
	~ScavTrap();
	void attack(const std::string &target);
	void guardGate();
};

#endif
