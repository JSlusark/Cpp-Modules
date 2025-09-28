#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include <iosfwd> // for std::ostream forward-decl
#include "./Form.hpp"
#include "./utils.hpp"

class Bureaucrat
{
private:
	// attributes
	const std::string _name;
	int _grade; // ranges from 1(high) to 150 (low)
	// class utils
	void validateGrade(int grade);
	static const int TOO_HIGH = 1;
	static const int TOO_LOW = 150;

public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);			// Copy constructor
	Bureaucrat &operator=(const Bureaucrat &other); // Copy assignment operator
	~Bureaucrat();									// Destructor
	// accessors
	std::string getName() const;
	int getGrade() const;
	// modifiers
	void decrementGrade(); // if out of ranhge throe cnstructor error
	void incrementGrade(); // if out of ranhge throe cnstructor error
	void signForm(Form &f);

	/*
	 - exception throws signals errors
	 - std:: exception is the base class of standard exception
	 - defines the virtual method *what() that returns a description string
	 - Without inheritance, throws still happens, but cannot use the uniform interface e.what().
	 - inheritance permits consistency with c++ standard
	 - Ability to handle all exceptions through a single catch (std::exception &e).
	 - A standard way to return a message via what().
	 - Public inheritance means is-a.

	*/
	// expceptions
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return (C_RED "[EXCEPTION] " C_RESET "Grade is too high ( < 1)");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return (C_RED "[EXCEPTION] " C_RESET "Grade is too low ( > 150)");
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
#endif
