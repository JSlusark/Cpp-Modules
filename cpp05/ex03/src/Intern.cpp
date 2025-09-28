#include "../headers/Intern.hpp"

/* Parametarised constructor */
Intern::Intern()
{
	std::cout << "Intern created by parametarise constructor " << std::endl;
}

/* Copy constructor: the object is costucted and copies variable at the same tome */
Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout << "Intern created by copy constructor " << std::endl;
}

/* Copy assignment operator: the ojetct is already cinstructed elsewhere, so we just assign copies of props */
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
	std::cout << "Intern was assigned by copy assignment " << std::endl;
	return *this;
}

/* Destructor */
Intern::~Intern()
{
	std::cout << "Intern was destroyed by destructor " << std::endl;
}

// helper "factory" functions
AForm *createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
	std::cout << C_GRAY << "[LOG]" << C_RESET << " Intern received request to create form " << name << std::endl;

	const t_form formsList[3] = {
		{"presidential pardon", &createPresidential},
		{"robotomy request", &createRobotomy},
		{"shrubbery creation", &createShrubbery}
	};

	for (int i = 0; i < 3; i++)
	{
		if (formsList[i].name == name)
		{
			std::cout << C_GREEN << "[SUCCESS]" << C_RESET << " Intern successfully creates " << name << std::endl;
			return formsList[i].object(target);
		}
	}
	std::cout << C_RED << "[ERROR]" << C_RESET << " Intern caught an error in the request, form \"" << name << "\" does not exist" << std::endl;
	return NULL;
}
