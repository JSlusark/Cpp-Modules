#include "../headers/MutantStack.hpp"

/* Parametarised constructor */
template <typename T, class Container>
MutantStack<T, Container>::MutantStack()
{
	logMessage(DEFAULT_C, "MutantStack object created");
}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other) : std::stack<int>(other)
{
	logMessage(COPY_C, "MutantStack copy created");
}

template <typename T, class Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &other) {
    std::stack<T, Container>::operator=(other); // calls base class assignment operator
	logMessage(ASSIGN_OP, "MutantStack assigned");
    return *this;
}


/* Destructor */
template <typename T, class Container>
MutantStack<T, Container>::~MutantStack()
{
	logMessage(DESTRUCTOR, "MutantStack object destroyed");
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin() { return this->c.begin(); } // c is nested protected member of std::stack

template <typename T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::end() { return this->c.end(); }

template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::begin() const { return this->c.begin(); }

template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::end() const { return this->c.end(); }

template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rbegin() { return this->c.rbegin(); }

template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rend() { return this->c.rend(); }

template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rbegin() const { return this->c.rbegin(); }

template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rend() const { return this->c.rend(); }