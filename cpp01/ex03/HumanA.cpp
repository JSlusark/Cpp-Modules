#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon), name(name) {}

HumanA::~HumanA() {}

void HumanA::Attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
