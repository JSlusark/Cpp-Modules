#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <iosfwd> // for std::ostream forward-decl
#include "./colors.hpp"

// Forward declaration: breaks circular include (form.hpp present in bureaucrat)
class Bureaucrat;

class AForm
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
	// AForm();
	AForm(const std::string &name, int gradeCanSign, int gradeCanExec); // Parametarised constructor
	AForm(const AForm &other);											// Copy constructor
	AForm &operator=(const AForm &other);								// Copy assignment operator
	virtual ~AForm();													// Destructor

	std::string getName() const;
	bool getSignedStatus() const;
	int getSignPermission() const;
	int getExecPermission() const;
	void beSigned(const Bureaucrat &b); // changes the form status to signed if bur grad is high enough

	virtual void execute(Bureaucrat const &executor) const = 0; // Pure virtual function

	// expceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return (C_RED "[Exception]" C_RESET "AForm grade is too high ( < 1)");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return (C_RED "[Exception]" C_RESET " AForm grade is too low ( > 150)");
		}
	};
	class UnsignedForm : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return (C_RED "[Exception]" C_RESET " AForm was not signed");
		}
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &f);
#endif
