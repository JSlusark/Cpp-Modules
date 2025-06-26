#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    Weapon& weapon;
    std::string name;

public:
    HumanA(std::string name, Weapon& weapon); // has to take weapon in constructor
    ~HumanA();
    void Attack();
};

#endif