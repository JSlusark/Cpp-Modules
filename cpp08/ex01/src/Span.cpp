#include "../headers/Span.hpp"
#include "../headers/utils.hpp"
#include <iostream>

// /* Default constructor */
// Span::Span()
// {
// 	std::cout << "Span created by default constructor " << std::endl;
// }

/* Parametarised constructor */
Span::Span(const unsigned int N) : _MAX(N)
{
	// logMessage(PARAM_C, "Span object created");
}

/* Copy constructor: constructs new object as a copy of an object */
Span::Span(const Span &other) : _MAX(other._MAX), _container(other._container)
{
	// logMessage(COPY_C, "Span object created");
	std::cout << "Span created by copy constructor " << std::endl;
}

/* Copy assignment operator: we copy attributes only as object was already constucted */
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		// BaseClass::operator=(other); // should add this instead if derived class
		this->_MAX = other._MAX; // placeholder
		this->_container = other._container;
	}
	// logMessage(ASSIGN_OP, "Span attributes assigned");
	return *this;
}

/* Destructor */
Span::~Span()
{
	// logMessage(DESTRUCTOR, "Span object destroyed");
}

void Span::addNumber(int number)
{
	if (_container.size() >= _MAX) // as pushes starts from 0 and goes to N-1
		throw LimitReachedException();
	_container.push_back(number); // adds up number to vector
}

void Span::addNumber(const std::vector<int> &range) // we lose sizeof value as it decays to pointer
{
	for (size_t i = 0; i < range.size(); i++)
	{
		if (_container.size() >= _MAX) // as pushes starts from 0 and goes to N-1
			throw LimitReachedException();
		_container.push_back(range[i]); // adds up number to vector
	};
}


int Span::shortestSpan() const
{
	if (_container.size() < 2)
		throw UncomparableException();

	std::vector<int> tmp(_container); // copy contrusting container to tmp
	std::sort(tmp.begin(), tmp.end());
	int next = tmp[1] - tmp[0]; // initializing
	for (size_t i = 1; i < tmp.size() - 1; i++)
	{
		int curr = tmp[i + 1] - tmp[i];
		if (curr < next)
			next = curr;
		if (next == 0) // can't get smaller so better to stop here to avoid unnecessary iterations
			break;
	}
	return next;
}

int Span::longestSpan() const
{
	if (_container.size() < 2)
		throw UncomparableException();
	int min = *std::min_element(_container.begin(), _container.end());
	int max = *std::max_element(_container.begin(), _container.end());
	return max - min;
}

const char *Span::LimitReachedException::what() const throw()
{
	return "Exception: Span reached maximum capacity";
}

const char *Span::UncomparableException::what() const throw()
{
	return "Exception: Not enough numbers to find a span";
}