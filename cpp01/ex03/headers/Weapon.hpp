#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include "colors.hpp"
#include "colors.hpp"

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string type); //c constructor
    ~Weapon(); // destructor
    void assignRandomName();
    void setType(std::string type); // sets type using the new value passed as a parameter.
    const std::string &getType() const; // returns a const reference (&) to type
};

#endif