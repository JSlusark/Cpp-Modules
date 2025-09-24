#include "../headers/ShrubberyCreationForm.hpp"

/* Parametarised constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm created by parametarise constructor " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copied" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other); // delegate to base assignment
		_target = other._target;
	}
	std::cout << "ShrubberyCreationForm assigned" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

void ShrubberyCreationForm::executeForm() const
{
	std::ofstream file((_target + "_shrubbery").c_str()); // need to convert as c because ofstream and c++98
	if (!file.is_open())
		throw std::runtime_error(C_RED "Could not open file for shrubbery" C_RESET);
	file << "🌴🌲🌴🌳🌴" << std::endl;
	file.close();
	std::cout  << C_GREEN << "[SUCCESS] " << C_RESET << this->getName() << " form was created as " << _target << "_shrubbery file" << std::endl;
}
