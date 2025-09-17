#include "../headers/PresidentialPardonForm.hpp"

/* Parametarised constructor */
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
	std::cout << "PresidentialPardonForm  created by parametarise constructor " << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
}
