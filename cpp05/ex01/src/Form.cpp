#include "../headers/Form.hpp"
#include "../headers/Bureaucrat.hpp"

void Form::validateGrade(int grade) const
{

	if (grade < TOO_HIGH)
		throw GradeTooHighException();
	if (grade > TOO_LOW)
		throw GradeTooLowException();
}
/* Parametarised constructor */
Form::Form(const std::string &name, int gradeCanSign, int gradeCanExec) : _name(name), _isSigned(false), _gradeCanSign(gradeCanSign), _gradeCanExec(gradeCanExec)
{
	validateGrade(_gradeCanSign);
	validateGrade(_gradeCanExec);
	logMessage(PARAM_C,  "Form " + _name + " created ");
}

/* Copy constructor: constructs new object as a copy of an object */
Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeCanSign(other._gradeCanSign), _gradeCanExec(other._gradeCanExec)
{
	logMessage(COPY_C,  "Form " + _name + " copy created");
}

/* Copy assignment operator: we copy attributes only as object was already constucted */
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		// only non-const member is _isSigned
		this->_isSigned = other._isSigned;
	}
	logMessage(ASSIGN_OP,  "Form " + _name + " assigned copy");
	return *this;
}

/* Destructor */
Form::~Form()
{
	logMessage(DESTRUCTOR, "Form " + _name + " destroyed");
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
		logMessage(SUCCESS, "Bureaucrat " + b.getName() + " signed form " + _name);
	}
	else
	{
		logMessage(ERROR, "Bureaucrat " + b.getName() + " cannot sign form " + _name);
		throw GradeTooLowException();
	}
}

// stream
std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "-----------------------------------\n"
	   << "	Form: " << f.getName() << "\n"
	   << "	Is signed: " << (f.getSignedStatus() ? "Yes" : "No") << "\n"
	   << "	Sign grade required: " << f.getSignPermission() << "\n"
	   << "	Exec grade required: " << f.getExecPermission() << "\n"
	   << "-----------------------------------";
	return os;
}
