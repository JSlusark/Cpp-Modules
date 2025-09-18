#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	typedef struct s_form
	{
		std::string name;
		 AForm* (*object)(const std::string &target); // function pointer to simulate lambda
	} t_form;

public:
	Intern(void);
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern(void);

	AForm *makeForm(const std::string &name, const std::string &target) const;
};