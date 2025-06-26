
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

#define C_RESET "\033[0m"
#define C_RED "\033[38;2;255;85;85m"
#define C_GREEN "\033[38;2;0;255;128m"
#define C_YELLOW "\033[38;2;255;255;0m"
#define C_MAGENTA "\033[38;2;255;0;255m"
#define C_WHITE "\033[38;2;255;255;255m"
#define C_PURPLE "\033[38;2;180;0;255m"
#define C_BOLD_WHITE "\033[1m\033[38;2;255;255;255m"
#define BG_DARK_PURPLE "\033[48;2;50;0;80m"

class ClapTrap
{
	private:
		std::string name;
		const int HIT_POINTS = 10;
		const int ENERGY_POINTS = 10;
		const int ATTACK_DAMAGE = 10;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
