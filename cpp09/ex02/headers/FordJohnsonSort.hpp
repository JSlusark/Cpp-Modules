#pragma once
#include "./debug.hpp"
#include "./PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits>    // <--- added
#include <stdexcept> // <--- added for exceptions
#include <string>    // <--- ensure std::string
#include <ctime>     // clock()
#include <sys/time.h>
#include <iomanip>
#include <sstream>
#include <climits>   // add for INT_MAX

// Class version (same name; allowed but distinct from function)
template <template<typename, typename> class Container>
class FordJohnsonSort
{
private:
    int iterationResult;
    Container<int, std::allocator<int> > result; // will be a template
    size_t originalSize;
    size_t resultSize;
    std::clock_t cpu_start;  // stored start CPU time
    std::clock_t cpu_end;    // stored end CPU time
    struct timeval tv_start; // wall start (kept if you later want wall time)
    struct timeval tv_end;   // wall end
    int comparisonLimit;
    int comparisonResult; 
    std::string errorMessage;  
    
    // http://en.cppreference.com/w/cpp/container.html
    // use chatgpt brainstorming message to explain deque vs stack from ex01
    
    /* ------------------ SORTING FUNCTIONS ------------------ */
    void sort();
    void recursion(Container<int, std::allocator<int> > &recursedSet);
    
    /* ------------------ PRINT DEBUG ------------------ */
    void showSequence(const std::string &state, const Container<int, std::allocator<int> > &container, size_t containerSize);
    
    /* ------------------ RESULT CHECKING UTILS ------------------ */
    bool isSorted(const Container<int, std::allocator<int> > &container);
    bool wrongResult();
    bool isValidNumber(std::string &s, int &conversion);
    int  maxComparisons(int n);


public:
    /* ------------------ CONSTRUCTORS ------------------ */
    FordJohnsonSort(int argc, char **argv, Container<int, std::allocator<int> > container); // vect will me a template later
    ~FordJohnsonSort();
    FordJohnsonSort(const FordJohnsonSort &other);
    FordJohnsonSort &operator=(const FordJohnsonSort &other);

    /* ------------------ CHECKS AND PRINT RESULT ------------------ */
    void showResult();
};


#include "../src/FordJohnsonSort.tpp"
