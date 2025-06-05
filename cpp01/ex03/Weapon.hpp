#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    Weapon();
    ~Weapon();
    const std::string& getType(); // returns a conatcta reference to type
    void setType(std::string& value); // sets type using the new value passed as a parameter.
};