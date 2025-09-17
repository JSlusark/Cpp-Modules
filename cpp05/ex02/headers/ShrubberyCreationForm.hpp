#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <iosfwd> // for std::ostream forward-decl
#include "./colors.hpp"
#include "AForm.hpp"

// Forward declaration: breaks circular include (form.hpp present in bureaucrat)
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	ShrubberyCreationForm(const std::string &target); // Parametarised constructor
	void execute(Bureaucrat const &executor) const;
};

#endif
