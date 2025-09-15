#include "../headers/Bureaucrat.hpp"

void Bureaucrat::validateGrade(int grade)
{
	if (grade < TOO_HIGH)
		throw GradeTooHighException();
	if (grade > TOO_LOW)
		throw GradeTooLowException();
}

/* Default constructor */
// Bureaucrat::Bureaucrat(void)
// {
// 	std::cout << "needs params?" << std::endl;
// 	return;
// }

/* Parametarised constructor */
Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	validateGrade(_grade);
	std::cout << "Bureaucrat created by parametarise constructor " << std::endl;
}

/* Copy constructor: the object is costucted and copies variable at the same tome */
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat created by copy constructor " << std::endl;
}

/* Copy assignment operator: the ojetct is already cinstructed elsewhere, so we just assign copies of props */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	std::cout << "Bureaucrat assigned by copy assignment " << std::endl;
	return *this;
}

/* Destructor */
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destroyed by destructor " << std::endl;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{ // decreases
	validateGrade(_grade - 1);
	--_grade;
}

void Bureaucrat::decrementGrade()
{ // increases
	validateGrade(_grade + 1);
	++_grade;
}

// stream
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	return os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}