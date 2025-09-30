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
	logMessage(PARAM_C, "Span object created");
}

/* Copy constructor: constructs new object as a copy of an object */
Span::Span(const Span &other) : _MAX(other._MAX)
{
	logMessage(COPY_C, "Span object created");
	std::cout << "Span created by copy constructor " << std::endl;
}

/* Copy assignment operator: we copy attributes only as object was already constucted */
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		// BaseClass::operator=(other); // should add this instead if derived class
		this->_MAX = other._MAX; // placeholder
	}
	logMessage(ASSIGN_OP, "Span attributes assigned");
	return *this;
}

/* Destructor */
Span::~Span()
{
	logMessage(DESTRUCTOR, "Span object destroyed");
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _MAX)
		throw std::runtime_error("Span is full");
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("Not enough numbers to find a span");

	std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> minMax =
		std::minmax_element(_numbers.begin(), _numbers.end());
	return *minMax.second - *minMax.first;
}

int Span::longestSpan() const
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("Not enough numbers to find a span");

	std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> minMax =
		std::minmax_element(_numbers.begin(), _numbers.end());
	return *minMax.second - *minMax.first;
}