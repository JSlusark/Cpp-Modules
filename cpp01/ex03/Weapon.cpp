#include "Weapon.hpp"

Weapon::Weapon() : type{}
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType(){

    type;

}
void Weapon::setType(std::string& value){
    type = value;
}