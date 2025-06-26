#include "../headers/Harl.hpp"

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

int Harl::getAction(const std::string &level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			return i;
	}
	return -1;
}

void Harl::complain(std::string level)
{
	int action = getAction(level);
		switch (action) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			this->debug();
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			this->info();
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			this->warning();
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			this->error();
			break; // break here as it will have to call all functions following the passes level
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
