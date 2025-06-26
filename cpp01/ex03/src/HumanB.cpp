#include "../headers/HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL), name(name) {}

HumanB::~HumanB() {}

void HumanB::SetWeapon(Weapon &type)
{
	weapon = &type;
}

void HumanB::Attack()
{
	if (weapon)
		std::cout << C_PURPLE << name << C_RED << " attacks with their " << weapon->getType() << C_RESET << std::endl;
	else
		std::cout << C_YELLOW << "[Warning]: "<< name << " cannot attack as weapon was not set after construction!" <<C_RESET << std::endl;
}
