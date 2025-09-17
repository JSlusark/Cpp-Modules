#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <iosfwd> // for std::ostream forward-decl
#include "./colors.hpp"
#include "AForm.hpp"

// Forward declaration: breaks circular include (form.hpp present in bureaucrat)
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	// RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target); // Parametarised constructor
	void execute(Bureaucrat const &executor) const;
};

#endif
