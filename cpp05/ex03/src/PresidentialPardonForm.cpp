#include "../headers/PresidentialPardonForm.hpp"

/* Parametarised constructor */
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm created by parametarise constructor " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm copied" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other); // delegate to base assignment
		_target = other._target;
	}
	std::cout << "PresidentialPardonForm assigned" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

void PresidentialPardonForm::executeForm() const
{
	std::cout << C_GREEN << "[SUCCESS]" << C_RESET << _target << " has been pardoned by Zaphod Beeblebrox 🧐" << std::endl;
}
