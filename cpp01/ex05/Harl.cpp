#include "Harl.hpp"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	/*
		Instead of using parallel arrays, I decided to regroup my name and pointers in a struct array, to pair
		each level its corresponding member function.
		I made this decision not only because it is the easiest and cleanest to maintain (bundles values in key value pairs),
		but better replicates std::map or lambda functions.
	*/

	FunctionLevels action[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}};
	bool validLevel = false;
	for (int i = 0; i < 4; i++)
	{
		if (action[i].name == level)
		{
			std::cout << "[" << level << "]" << std::endl;
			(this->*action[i].func)();
			validLevel = true;
		}
	}
	if (!validLevel)
		std::cout << "[" << level << "]\n" << "I have no time to lose! Call me when you have a valid argument!" << std::endl;
	std::cout << std::endl;
}
