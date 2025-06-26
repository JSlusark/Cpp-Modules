#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon* weapon;
	std::string name;

public:
	HumanB(std::string name); // does not need to have weapon in its constructor
	~HumanB();
	void Attack();
	void SetWeapon(Weapon& type);
};

#endif