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

/* ./PmergeMe $(shuf -i 1-10 -n 3000 | tr "\n" " ") */

// Class version (same name; allowed but distinct from function)
class fordJohnsonSort
{
private:
    int iterationResult;
    int comparisonResult;
    std::vector<int> result; // will be a template
    size_t originalSize;
    size_t resultSize;
    std::clock_t cpu_start;  // stored start CPU time
    std::clock_t cpu_end;    // stored end CPU time
    struct timeval tv_start; // wall start (kept if you later want wall time)
    struct timeval tv_end;   // wall end
    int comparisonLimit;
    std::string errorMessage;
    // http://en.cppreference.com/w/cpp/container.html
    // use chatgpt brainstorming message to explain deque vs stack from ex01

public:
    fordJohnsonSort(int argc, char **argv, std::vector<int> received_container); // vect will me a template later
    ~fordJohnsonSort();

    // --------------  TO ADD AT THE END  -----------------
    // copy contructor + assignment operator !!!!
    // fordJohnsonSort(const fordJohnsonSort &other);
    // fordJohnsonSort &operator=(const fordJohnsonSort &other);

    void sort();
    int wrongResult();
    void showResult();

    void recursion(std::vector<int> &recursed_container);
    void pairingPhase(PmergeMe &recursed_containert);
    void insertionPhase(PmergeMe &recursed_container);
};
