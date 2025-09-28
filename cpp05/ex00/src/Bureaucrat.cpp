#include "../headers/Bureaucrat.hpp"

void Bureaucrat::validateGrade(int grade)
{

	if (grade < TOO_HIGH)
		throw GradeTooHighException();
	if (grade > TOO_LOW)
		throw GradeTooLowException();
}

/* Parametarised constructor */
Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	validateGrade(_grade);
	logMessage(PARAM_C,  "Bureaucrat " + _name + " created ");
}

/* Copy constructor: the object is costucted and copies variable at the same tome */
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	logMessage(COPY_C,  "Bureaucrat " + _name + " copy created");
}

/* Copy assignment operator: the ojetct is already cinstructed elsewhere, so we just assign copies of props */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	logMessage(ASSIGN_OP,  "Bureaucrat " + _name + " assigned copy");
	return *this;
}

/* Destructor */
Bureaucrat::~Bureaucrat()
{
	logMessage(DESTRUCTOR, "Bureaucrat " + _name + " destroyed");
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
	logMessage(LOG, "Incrementing --" );
	validateGrade(_grade - 1);
	--_grade;
	std::cout << C_GREEN << "[SUCCESS] " << C_RESET << _name << "Incremented to " << _grade << std::endl;
}

void Bureaucrat::decrementGrade()
{ // increases
	logMessage(LOG, "Decrementing ++" );
	validateGrade(_grade + 1);
	++_grade;
	std::cout << C_GREEN << "[SUCCESS] " << C_RESET << _name << "'s grade decremented to " << _grade << std::endl;

}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	return os << C_GRAY << "Name: " << C_RESET << b.getName() << C_GRAY << " Grade: " << C_RESET << b.getGrade();
}