#include "../headers/ShrubberyCreationForm.hpp"

/* Parametarised constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm  created by parametarise constructor " << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
}
