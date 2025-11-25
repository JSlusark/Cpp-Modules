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

// Class version (same name; allowed but distinct from function)
class fordJohnsonSort
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
    int comparisonResult; // added here for tester purposes
    std::string errorMessage;
    // http://en.cppreference.com/w/cpp/container.html
    // use chatgpt brainstorming message to explain deque vs stack from ex01
    void sort();
    void recursion(std::vector<int> &recursedSet);
    void pairingPhase(PmergeMe &recursedSett);
    void insertionPhase(PmergeMe &recursedSet);
    
    int wrongResult();

public:
    fordJohnsonSort(int argc, char **argv); // vect will me a template later
    ~fordJohnsonSort();


    // --------------  TO ADD AT THE END  -----------------
    // copy contructor + assignment operator !!!!
    // fordJohnsonSort(const fordJohnsonSort &other);
    // fordJohnsonSort &operator=(const fordJohnsonSort &other);

    void showResult();

};
