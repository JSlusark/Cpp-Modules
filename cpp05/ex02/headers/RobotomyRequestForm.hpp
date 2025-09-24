#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

// Forward declaration: breaks circular include (form.hpp present in bureaucrat)
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	// RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target); // Parametarised constructor
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();
	void executeForm() const;
};

#endif
