#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string type);
    ~Weapon();
    const std::string &getType() const;    // returns a const reference to type
    void setType(std::string value); // sets type using the new value passed as a parameter.
};
#endif