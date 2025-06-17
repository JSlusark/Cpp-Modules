#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL), name(name) {}

HumanB::~HumanB() {}

void HumanB::SetWeapon(Weapon& type){
	weapon = &type;
}

void HumanB::Attack()
{
	if(weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " cannot attack as no weapon type was set!" << std::endl;
}
