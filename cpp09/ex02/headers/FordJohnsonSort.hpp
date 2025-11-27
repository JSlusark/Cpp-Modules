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
class FordJohnsonSort
{
private:
    int iterationResult;
    std::vector<int> result; // will be a template
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
    void recursion(std::vector<int> &recursedSet);
    void pairingPhase(PmergeMe &recursedSett);
    void insertionPhase(PmergeMe &recursedSet);
    
    /* ------------------ PRINT DEBUG ------------------ */
    void showSequence(const std::string &state, const std::vector<int> &container, size_t containerSize);
    
    /* ------------------ RESULT CHECKING UTILS ------------------ */
    bool isSorted(const std::vector<int> &container);
    bool wrongResult();
    bool isValidNumber(std::string &s, int &conversion);
    int  maxComparisons(int n);


public:
    /* ------------------ CONSTRUCTORS ------------------ */
    FordJohnsonSort(int argc, char **argv); // vect will me a template later
    ~FordJohnsonSort();
    FordJohnsonSort(const FordJohnsonSort &other);
    FordJohnsonSort &operator=(const FordJohnsonSort &other);

    /* ------------------ CHECKS AND PRINT RESULT ------------------ */
    void showResult();
};
