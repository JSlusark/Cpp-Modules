#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include <string>
#include <iostream>
#include <exception>
#include <iosfwd> // for std::ostream forward-decl
#include "./colors.hpp"
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	// PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target); // Parametarised constructor
	void execute(Bureaucrat const &executor) const;
};

#endif