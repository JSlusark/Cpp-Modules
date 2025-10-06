#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>

class Span
{
private:
	unsigned int _MAX; // maximum
	std::vector<int> _container;

public:
	// Span();								// Default constructor
	Span(const unsigned int N);			// Parametarised constructor
	Span(const Span &other);			// Copy constructor
	Span &operator=(const Span &other); // Copy assignment operator
	~Span();							// Destructor

	void addNumber(int number);
	void addNumber(const std::vector<int> &range); // overload with vec as array decays to pointer
	int shortestSpan() const; // smallest difference between any two numbers within the container
	int longestSpan() const; // largest difference between any two numbers within the container

	class LimitReachedException : public std::exception {
        const char* what() const throw();
    };

    class UncomparableException : public std::exception {
        const char* what() const throw();
    };
};

#endif
