#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <iosfwd> // for std::ostream forward-decl
#include "./utils.hpp"

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

	// added initExecution to avoid to write the same logic in child classes
	void initExecution(Bureaucrat const &executor) const;
	virtual void executeForm() const = 0; // Pure virtual function

	/*
	Exceptions do not need to be declared virtual as they are already by default:
	https://en.cppreference.com/w/cpp/error/exception.html so doing so won't really do anything
	other than wasting typing
	*/
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return (C_RED "[EXCEPTION]" C_RESET "Bureacrat grade is too high for form action requirement");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return (C_RED "[EXCEPTION]" C_RESET " Bureacrat grade is too low for form action requirement");;
		}
	};
	class UnsignedFormException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return (C_RED "[EXCEPTION]" C_RESET " Form was not signed");
		}
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &f);
#endif
