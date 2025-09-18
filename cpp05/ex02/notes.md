-   Form is converted to Aform and needs to be an abstract class (means it cannot be instantiated, unless if called via pointer?)
-   The other forms are derivative classes of AForm
-   AForm has a pure virtual function execute that needs to be implemented in the derived classes
-   Added an exception for executing an unsigned form
-   derivatrive class inheritance is public which means all public members of their base class(Aform) are public

If I make execute() pure virtual, every child has to re-implement the checks happening in execute, which duplicates code. The elegant solution is making executeAction pure virtual and implementing the checks in AForm::execute.
void AForm::execute(Bureaucrat const& executor) const {
if (!isSigned) throw FormNotSignedException();
if (executor.getGrade() > gradeToExec) throw GradeTooLowException();
executeAction(); // polymorphic call
}

-   Pure virtual fnctions are functions witj = 0 in the declaration
    virtual void executeAction() const = 0;
    -   This makes the class abstract and cannot be instantiated

✅ Summary of the clean design:
AForm has:
	- void execute(Bureaucrat const&) const (normal, does checks).
	- virtual ~AForm() (virtual destructor).
	- ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm override executeAction().
	- virtual void executeAction() const = 0; (pure virtual, implemented by children).

-   Why virtual in based class destructor: If you delete a derived class object through a base class pointer and the base class destructor is not virtual, the derived class destructor will not be called, leading to resource leaks and undefined behavior. By declaring the base class destructor as virtual, you ensure that the correct destructor is called for both the base and derived classes, allowing for proper cleanup of resources.

To remember:

-   Overloading: same function name, different parameters (either in type or number). Decided at compile time (static polymorphism, which is not actually polymorphism). Does not require inheritance.
    ---> Static polymorphism: compile-time - overloading, templates.
-   Overriding: child class provides its own implementation of a function declared virtual in the parent. Decided at runtime (dynamic polymorphism, actual polymorphism). Requires inheritance.
    ---> Dynamic polymorphism = runtime - overriding virtual functions.
-   Abstract class: a class that cannot be instantiated, often containing pure virtual functions.
-   Virtual functions: allow derived classes to provide specific implementations for functions defined in the base class.
-   Pure virtual functions: virtual functions with = 0 in the declaration, making the class abstract (cannot be instantiated).
