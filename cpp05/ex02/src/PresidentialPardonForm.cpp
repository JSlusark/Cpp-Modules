#include "../headers/PresidentialPardonForm.hpp"

/* Parametarised constructor */
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential", 25, 5), _target(target)
{
		logMessage(PARAM_C, "PresidentialPardonForm created");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target)
{
	logMessage(COPY_C, "PresidentialPardonForm copy created");
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other); // delegate to base assignment
		_target = other._target;
	}
	logMessage(ASSIGN_OP, "PresidentialPardonForm assigned copy");
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	logMessage(DESTRUCTOR, "PresidentialPardonForm destroyed");

}

void PresidentialPardonForm::executeForm() const
{
	std::cout << C_GREEN << "[SUCCESS]" << C_RESET << _target << " has been pardoned by Zaphod Beeblebrox 🧐" << std::endl;
}
