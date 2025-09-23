#include "../headers/Base.hpp"

Base *generate(void) // randomly instantiates A, B, or C and returns a Base pointer to the instance
{
	int r = rand() % 3;
	if (r == 0)
		return new A();
	if (r == 1)
		return new B();
	return new C();
}

// overloaded functions to identify the actual type of the object pointed to by p
void identify(Base *p) // by pointer
{
	if (!p)
	{
		logMessage(ERROR, "Null pointer passed");
		return;
	}

	logMessage(LOG, "Identifying by pointer:");
	if (dynamic_cast<A *>(p))
		logMessage(C_CYAN "[POINTER]" C_RESET, "Identified type *A");
	else if (dynamic_cast<B *>(p))
		logMessage(C_CYAN "[POINTER]" C_RESET, "Identified type *B");
	else if (dynamic_cast<C *>(p))
		logMessage(C_CYAN "[POINTER]" C_RESET, "Identified type *C");
	else
		logMessage(ERROR, "Pointer not recognized");
}

void identify(Base &p)
{
	logMessage(LOG, "Identifying by reference:");
	// nested try/catch blocks so that the catch returns only if all three dynamic_casts fail
	try
	{
		(void)dynamic_cast<A &>(p);
		logMessage(C_YELLOW "[REFERENCE]" C_RESET, "Identified type &A");
	}
	catch (...)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			logMessage(C_YELLOW "[REFERENCE]" C_RESET, "Identified type &B");
		}
		catch (...)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				logMessage(C_YELLOW "[REFERENCE]" C_RESET, "Identified type &C");
				return;
			}
			catch (...)
			{
				logMessage(ERROR, "Refence not recognized");
			}
		}
	}
}