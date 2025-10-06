#pragma once
#include <stack>
#include <deque>

template <typename T, class Container = std::deque<T> > // deque is default underlying container for stack
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack();								// Default constructor
	// MutantStack(const unsigned int N);			// Parametarised constructor
	MutantStack(const MutantStack &other);			// Copy constructor
	MutantStack &operator=(const MutantStack &other); // Copy assignment operator
	~MutantStack();							// Destructor

 typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

#include "../src/MutantStack.tpp"