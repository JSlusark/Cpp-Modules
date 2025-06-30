
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "colors.hpp"

/*
https://www.geeksforgeeks.org/cpp/inheritance-in-c/

class DerivativeClass : public/protected/private BaseClass

3 inheritance modes:
- public: base class public members and protected members can be accessed from derived class (private members can't be accessed directly but with getter/setter of base class or by declaring derived class a friend class )
- protected: base class public and protected members become protected in the derived class
- private: default mode if unspecified,  base class' public and protected members become private in the derived class
*/

// Derived class (child) - the parent name is added with ":"
class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap(); // default constructor (does not need params)
	ScavTrap(std::string name);
	// 	// copy contructor ?
	// 	// operator constructor ?
	~ScavTrap();
	void attack(const std::string &target); // overrides claptrap attack
	void guardGate();
};

#endif
