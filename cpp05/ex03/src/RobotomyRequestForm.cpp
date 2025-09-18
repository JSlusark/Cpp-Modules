#include "../headers/RobotomyRequestForm.hpp"

/* Parametarised constructor */
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm created by parametarise constructor " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm copied" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other); // delegate to base assignment
		_target = other._target;
	}
	std::cout << "RobotomyRequestForm assigned" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

void RobotomyRequestForm::executeForm() const
{
	std::cout << C_GRAY << "[LOG]" << C_RESET << "* Drilling noises *\n";
	// rand() in C/C++ does not produce "true" random numbers. It is a pseudo-random
	// generator: it always produces the same sequence of numbers unless you change
	// its starting point (the "seed").
	// in main we use srand(seed) to set the starting point of time 0, without it, rand will give the same sequence of numbers
	if (std::rand() % 2)
		std::cout << C_GREEN << "[SUCCESS] " << C_RESET << _target << " has been completely robotomized 🤖" << std::endl;
	else
		std::cout << C_RED << "[FAIL]" << C_RESET << _target << " was not fully robotomized 🤖" << std::endl;
}
