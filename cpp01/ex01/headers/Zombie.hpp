#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>
#include <sstream>

#define C_RESET "\033[0m"
#define C_RED "\033[38;2;255;85;85m"
#define C_GREEN "\033[38;2;0;255;128m"
#define C_YELLOW "\033[38;2;255;255;0m"
#define C_MAGENTA "\033[38;2;255;0;255m"
#define C_WHITE "\033[38;2;255;255;255m"
#define C_PURPLE "\033[38;2;180;0;255m"
#define C_BOLD_WHITE "\033[1m\033[38;2;255;255;255m"
#define BG_DARK_PURPLE "\033[48;2;50;0;80m"

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void SetName(std::string);
	void announce(void);
};

// Stack and Heap functions
Zombie *zombieHorde(int N, std::string name);

#endif
