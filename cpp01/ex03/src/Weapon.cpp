#include "../headers/Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
    if (type.empty())
        assignRandomName();
}

Weapon::~Weapon()
{
}
void Weapon::assignRandomName()
{

    std::cout << C_YELLOW << "[Warning]: " << C_RESET << "The weapon name was passed as an empty string, therefore assigning random weapon!" << std::endl;
    this->type = "random weapon";
}

void Weapon::setType(std::string type)
{
    if (type.empty())
        assignRandomName();
    else
        this->type = type;
}
const std::string &Weapon::getType() const
{
    return type;
}