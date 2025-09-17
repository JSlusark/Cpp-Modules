#include "../headers/Bureaucrat.hpp"

void Bureaucrat::validateGrade(int grade)
{

	if (grade < TOO_HIGH)
		throw GradeTooHighException();
	if (grade > TOO_LOW)
		throw GradeTooLowException();
	// std::cout << C_YELLOW << "Grade validator: " C_RESET << _name << " has valid grade of " << _grade << "" << std::endl;
}

/* Parametarised constructor */
Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	validateGrade(_grade);
	std::cout << "Bureaucrat " << _name << " created by parametarise constructor " << std::endl;
}

/* Copy constructor: the object is costucted and copies variable at the same tome */
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat " << _name << " created by copy constructor " << std::endl;
}

/* Copy assignment operator: the ojetct is already cinstructed elsewhere, so we just assign copies of props */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	std::cout << "Bureaucrat " << _name << " was assigned by copy assignment " << std::endl;
	return *this;
}

/* Destructor */
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " was destroyed by destructor " << std::endl;
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
	// std::cout << "Incrementing --" << std::endl;
	validateGrade(_grade - 1);
	--_grade;
	std::cout << _name << "'s grande incremented to: " << _grade << std::endl;
}

void Bureaucrat::decrementGrade()
{ // increases
	// std::cout << "Decrementing ++" << std::endl;
	validateGrade(_grade + 1);
	++_grade;
	std::cout << _name << "Decremented to " << _grade << std::endl;
}

void Bureaucrat::signForm(Form &f) // add & to avoid creating a copy of f (without destructior uis called right after exception)
{
	try
	{
		// not adding conditional to sign if f.getSignature is true or false but would have been cool
		f.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

// // stream - allows to print the object props
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	return os << C_YELLOW << "Name: " << C_RESET << b.getName() << C_YELLOW << " Grade: " << C_RESET << b.getGrade();
}