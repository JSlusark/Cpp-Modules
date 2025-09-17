#include "../headers/RobotomyRequestForm.hpp"

/* Parametarised constructor */
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
	std::cout << "RobotomyRequestForm  created by parametarise constructor " << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
}
