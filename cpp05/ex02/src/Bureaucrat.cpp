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
	std::cout << C_GREEN << "[SUCCESS] " << C_RESET << _name << "'s grade incremented to " << _grade << std::endl;

}

void Bureaucrat::decrementGrade()
{ // increases
	logMessage(LOG, "Decrementing ++" );	validateGrade(_grade + 1);
	++_grade;
	std::cout << C_GREEN << "[SUCCESS] " << C_RESET << _name << "'s grade decremented to " << _grade << std::endl;

}

void Bureaucrat::signAForm(AForm &f) // add & to avoid creating a copy of f (without destructior uis called right after exception)
{
	std::cout << C_GRAY << "[LOG]" << C_RESET << " Bureaucrat " << _name << "(grade: " << _grade << ")" << " attempts to sign form " << f.getName() << "(grade required: " << f.getSignPermission() << ")" << std::endl;
	if (f.getSignedStatus()) // decided to add this personally
	{
		std::cout << C_GRAY << "[LOG]" << C_RESET <<  " Bureaucrat " << _name << " noticed that form " << f.getName() << " was already signed by another bureaucrat" << std::endl;
		return;
	}
	else
	{
		try
		{
			f.beSigned(*this);
			std::cout << C_GREEN << "[SUCCESS]" << C_RESET << " Bureaucrat " << _name << " signed form " << f.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << C_RED << "[FAIL]" << C_RESET << " Bureaucrat " << _name << " couldn’t sign " << f.getName() << " for following reason " << std::endl;
			std::cout << e.what() << std::endl;
		}
	}
}

void Bureaucrat::execAForm(AForm const &f)
{
	std::cout << C_GRAY << "[LOG]" << C_RESET << " Bureaucrat " << _name << "(grade: " << _grade << ")" << " attempts to execute form " << f.getName() << "(grade required: " << f.getExecPermission() << ")" << std::endl;

	try
	{
		// not adding conditional to sign if f.getSignature is true or false but would have been cool
		f.initExecution(*this);
		std::cout << C_GREEN << "[SUCCESS]" << C_RESET << " Bureaucrat " << _name << " executed form " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << C_RED << "[FAIL]" << C_RESET << " Bureaucrat " << _name << " couldn’t execute " << f.getName() << " for following reason " << std::endl;
		std::cout << e.what() << std::endl;
	}
}

// // stream - allows to print the object props
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	return os << C_GRAY << "Name: " << C_RESET << b.getName() << C_GRAY << " Grade: " << C_RESET << b.getGrade();
}