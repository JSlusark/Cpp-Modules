#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(nullptr), name(name) {}

HumanB::~HumanB() {}

void HumanB::SetWeapon(Weapon& type){
	weapon = &type;
}

void HumanB::Attack()
{
	if(weapon)
		std::cout << name << "attacks with their" << weapon->getType() << std::endl;
	else
		std::cout << name << "has no weapon!" << std::endl;
}
