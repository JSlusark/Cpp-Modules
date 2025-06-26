#include "../headers/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon), name(name) {
}

HumanA::~HumanA() {}

void HumanA::Attack()
{
    std::cout << C_MAGENTA << name << C_RED <<" attacks with their " << weapon.getType() << C_RESET << std::endl;
}
