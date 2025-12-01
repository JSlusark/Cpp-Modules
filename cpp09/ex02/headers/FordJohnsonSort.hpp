#pragma once
#include "./debug.hpp"
#include "./PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <string>   
#include <ctime>     
#include <sys/time.h>
#include <iomanip>
#include <sstream>
#include <climits>
#include <limits>    

/* 
    I made FordJohnson a "top-level" class that creates the sorted sequence of recerived intergers
    and that holds the info on how this was done.
*/

template <template<typename, typename> class Container>
class FordJohnsonSort
{
    private:
    size_t originalSize;
    int comparisonLimit;

    std::clock_t cpu_start;
    std::clock_t cpu_end;    
    struct timeval tv_start; 
    struct timeval tv_end;  

    std::string errorMessage;  

    /* ------------------ SORTING FUNCTIONS ------------------ */
    void sort(); // calls recursion
    void recursion(Container<int, std::allocator<int> > &recursedSet); // calls itself until no more changes are applicable to recursedSet
    
    
    /* ------------------ UTILITIES ------------------ */
    bool isValidNumber(std::string &s, int &conversion);
    void checkResult();
    bool isSorted(const Container<int, std::allocator<int> > &container); 
    bool wrongResult();
    int  maxComparisons(int n);
    
    
    
    public:
    /* ------------------ CONSTRUCTORS ------------------ */
    FordJohnsonSort(int argc, char **argv, Container<int, std::allocator<int> > container); 
    ~FordJohnsonSort();
    FordJohnsonSort(const FordJohnsonSort &other);
    FordJohnsonSort &operator=(const FordJohnsonSort &other);
    
    Container<int, std::allocator<int> > result; 
    size_t resultSize;
    int comparisonResult; 
    int iterationResult;
    
    /* ------------------ PRINT ------------------ */
    void printResult(const std::string &state, const Container<int, std::allocator<int> > &container, size_t containerSize);
};


#include "../src/FordJohnsonSort.tpp"
