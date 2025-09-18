#include "../headers/AForm.hpp"
#include "../headers/Bureaucrat.hpp"

void AForm::validateGrade(int grade) const
{

	if (grade < TOO_HIGH)
		throw GradeTooHighException();
	if (grade > TOO_LOW)
		throw GradeTooLowException();
	// std::cout << C_YELLOW << "Grade validator: " C_RESET << _name << " has valid grade of " << _grade << "" << std::endl;
}

// AForm::AForm()
// : _name("defaultName"), _isSigned(false), _gradeCanSign(150), _gradeCanExec(150) {
//     validateGrade(_gradeCanSign);
//     validateGrade(_gradeCanExec);
//     std::cout << "AForm " << _name << " created by default constructor" << std::endl;
// }

/* Parametarised constructor */
AForm::AForm(const std::string &name, int gradeCanSign, int gradeCanExec) : _name(name), _isSigned(false), _gradeCanSign(gradeCanSign), _gradeCanExec(gradeCanExec)
{
	validateGrade(_gradeCanSign);
	validateGrade(_gradeCanExec);
	std::cout << "AForm " << _name << " created by parametarise constructor " << std::endl;
}

/* Copy constructor: constructs new object as a copy of an object */
AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeCanSign(other._gradeCanSign), _gradeCanExec(other._gradeCanExec)
{
	std::cout << "AForm " << _name << " created by copy constructor " << std::endl;
}

/* Copy assignment operator: we copy attributes only as object was already constucted */
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		// only non-const member is _isSigned
		this->_isSigned = other._isSigned;
	}
	std::cout << "AForm " << _name << " was assigned by copy assignment " << std::endl;
	return *this;
}

/* Destructor */
AForm::~AForm()
{
	std::cout << "AForm " << _name << " was destroyed by destructor " << std::endl;
}

// getters
std::string AForm::getName() const { return _name; }
bool AForm::getSignedStatus() const { return _isSigned; }
int AForm::getSignPermission() const { return _gradeCanSign; }
int AForm::getExecPermission() const { return _gradeCanExec; }

// functions
void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _gradeCanSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::initExecution(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _gradeCanExec)
		throw GradeTooLowException();
	if (!_isSigned)
		throw UnsignedFormException();
	executeForm(); // <--- calls corresponding child function
}

// stream
std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "-----------------------------------\n"
	   << "	AForm: " << f.getName() << "\n"
	   << "	Is signed: " << (f.getSignedStatus() ? "Yes" : "No") << "\n"
	   << "	Sign grade required: " << f.getSignPermission() << "\n"
	   << "	Exec grade required: " << f.getExecPermission() << "\n"
	   << "-----------------------------------";
	return os;
}
