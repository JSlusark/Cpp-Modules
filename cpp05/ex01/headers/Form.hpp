#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <iosfwd> // for std::ostream forward-decl
#include "./colors.hpp"

// Forward declaration: breaks circular include (form.hpp present in bureaucrat)
class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeCanSign;
	const int _gradeCanExec;
	void validateGrade(int grade) const;
	static const int TOO_HIGH = 1;
	static const int TOO_LOW = 150;

public:
	// Form();
	Form(const std::string &name, int gradeCanSign, int gradeCanExec); // Parametarised constructor
	Form(const Form &other);										   // Copy constructor
	Form &operator=(const Form &other);								   // Copy assignment operator
	~Form();														   // Destructor

	std::string getName() const;
	bool getSignedStatus() const;
	int getSignPermission() const;
	int getExecPermission() const;
	void beSigned(const Bureaucrat &b); // changes the form status to signed if bur grad is high enough

	// expceptions
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return (C_RED "[Exception]" C_RESET "Form grade is too high ( < 1)");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return (C_RED "[Exception]" C_RESET " Form grade is too low ( > 150)");
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Form &f);
#endif
