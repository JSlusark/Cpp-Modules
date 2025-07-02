#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "colors.hpp"

class FragTrap : virtual public ClapTrap // virtual creates one shared copy between frag and scav trap, to avoid duplication in case another class inherits from them
{
private:
protected:
    static const int DEFAULT_HP = 100; // used this as assigning into the constructor will just assign to object and not class
    static const int DEFAULT_EP = 100; // used this as assigning into the constructor will just assign to object and not class
    static const int DEFAULT_AD = 30;  // used this as assigning into the constructor will just assign to object and not class

public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);            // Copy constructor
    FragTrap &operator=(const FragTrap &other); // Copy assignment operator
    ~FragTrap();
    void highFivesGuys(void);
};

#endif
