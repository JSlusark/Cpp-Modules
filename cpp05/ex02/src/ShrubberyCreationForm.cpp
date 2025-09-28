#include "../headers/ShrubberyCreationForm.hpp"

/* Parametarised constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{
		logMessage(PARAM_C, "ShrubberyCreationForm created");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
	logMessage(COPY_C, "ShrubberyCreationForm copy created");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other); // delegate to base assignment
		_target = other._target;
	}
	logMessage(ASSIGN_OP, "ShrubberyCreationForm assigned copy");
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	logMessage(DESTRUCTOR, "ShrubberyCreationForm destroyed");

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
