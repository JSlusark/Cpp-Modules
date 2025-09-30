#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept> // For std::runtime_error
#include <vector>

class Span
{
private:
	unsigned int _MAX; // maximum
	std::vector<int> _numbers;

public:
	// Span();								// Default constructor
	Span(const unsigned int N);			// Parametarised constructor
	Span(const Span &other);			// Copy constructor
	Span &operator=(const Span &other); // Copy assignment operator
	~Span();							// Destructor

	void addNumber(int number);
	int shortestSpan() const; // smallest difference between any two numbers within the container
	int longestSpan() const; // largest difference between any two numbers within the container
};

#endif
