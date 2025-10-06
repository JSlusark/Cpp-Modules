#pragma once
#include <stack>
#include <deque>
#include "../headers/utils.hpp"
/*
	We learn about template inheritance with Stack which is a template class that can hold any data type.
	Stack works as a wrapper, an adapter for an underlying container

	wtf is an adapter?
	Adapter is a design pattern that allows you to convert the interface of a class into another interface
	that a client expects. It allows classes with incompatible interfaces to work together by wrapping
	an instance of one class with an adapter class that provides the expected interface.



	with Mutantstack adds iteration suppoort to the stack base class
	stack is typcally a template class, because it can hold any data type, the default underlying container is deque (to to its push/pop from back)
	we add custom begin() and end() methods that return iterators (allowing iteration over the stack's elements)
	compatibility with lists, vectors -> how?

*/

template <typename T, class Container = std::deque<T> > // deque is default underlying container for stack
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack();								// Default constructor
	// MutantStack(const unsigned int N);			// Parametarised constructor
	MutantStack(const MutantStack &other);			// Copy constructor
	MutantStack &operator=(const MutantStack &other); // Copy assignment operator
	~MutantStack();							// Destructor

	// As Stack does not include iteratirs we have to rely on the underlying iterator types based on the wrapped container's iterators
	typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

	// sequential iterators
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
	// reverse iterators
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

#include "../src/MutantStack.tpp"