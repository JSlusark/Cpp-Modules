#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "colors.hpp"

class FragTrap : virtual public ClapTrap // virtual creates one shared copy between frag and scav trap, to avoid duplication in case another class inherits from them
{
private:
public:
    FragTrap();
    FragTrap(const std::string &name);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif
