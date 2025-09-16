#include "../headers/Form.hpp"
#include "../headers/Bureaucrat.hpp"

void Form::validateGrade(int grade) const
{

	if (grade < TOO_HIGH)
		throw GradeTooHighException();
	if (grade > TOO_LOW)
		throw GradeTooLowException();
	// std::cout << C_YELLOW << "Grade validator: " C_RESET << _name << " has valid grade of " << _grade << "" << std::endl;
}

// Form::Form()
// : _name("defaultName"), _isSigned(false), _gradeCanSign(150), _gradeCanExec(150) {
//     validateGrade(_gradeCanSign);
//     validateGrade(_gradeCanExec);
//     std::cout << "Form " << _name << " created by default constructor" << std::endl;
// }

/* Parametarised constructor */
Form::Form(const std::string &name, int gradeCanSign, int gradeCanExec) : _name(name), _isSigned(false), _gradeCanSign(gradeCanSign), _gradeCanExec(gradeCanExec)
{
	validateGrade(_gradeCanSign);
	validateGrade(_gradeCanExec);
	std::cout << "Form " << _name << " created by parametarise constructor " << std::endl;
}

/* Copy constructor: constructs new object as a copy of an object */
Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeCanSign(other._gradeCanSign), _gradeCanExec(other._gradeCanExec)
{
	std::cout << "Form " << _name << " created by copy constructor " << std::endl;
}

/* Copy assignment operator: we copy attributes only as object was already constucted */
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		// only non-const member is _isSigned
		this->_isSigned = other._isSigned;
	}
	std::cout << "Form " << _name << " was assigned by copy assignment " << std::endl;
	return *this;
}

/* Destructor */
Form::~Form()
{
	std::cout << "Form " << _name << " was destroyed by destructor " << std::endl;
}

// getters
std::string Form::getName() const { return _name; }
bool Form::getSignedStatus() const { return _isSigned; }
int Form::getSignPermission() const { return _gradeCanSign; }
int Form::getExecPermission() const { return _gradeCanExec; }

// functions
void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _gradeCanSign)
	{
		_isSigned = true;
		std::cout << "Bureaucrat " << b.getName() << " signed form " << _name << std::endl;
	}
	else
	{
		std::cout << "Bureaucrat " << b.getName() << " couldn’t sign" << _name << " for following reason: " << std::endl;
		throw GradeTooLowException();
	}
}

// stream
std::ostream &operator<<(std::ostream &os, const Form &f)
{
	return os << C_YELLOW << "Form: " << C_RESET << f.getName()
			  << C_YELLOW << "\n Is signed:" << C_RESET << f.getSignedStatus()
			  << C_YELLOW << "\n Sign grade required:" << C_RESET << f.getSignPermission()
			  << C_YELLOW << "\n Exec grade required:" << C_RESET << f.getExecPermission();
}