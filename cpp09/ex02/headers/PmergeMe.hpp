#pragma once
#include "./fordJohnsonSort.hpp"
#include "./debug.hpp"

class PmergeMe
{
private: // private per recursion?
    std::vector<int> input;
    std::vector<std::pair<int, int> > pairs; // pair container IS PROBLEMATIC WHEN ODD SIZE!!!
    std::vector<int> pend;                  // smaller values container
    std::vector<int> main;                  // bigger values container
    std::vector<size_t> jacobsthal;

    int counter;
    int remainderValue;
    int has_remainder;

    std::vector<size_t> findNumbers(size_t pend_size);
    std::vector<size_t> filledSequence(std::vector<size_t> &seq, size_t pend_size);
    std::vector<size_t> generateJacobsthal(); // n is size of pend_chain
    void createChains();

public:
    int recursionLvl;

    struct CountComparisons // functor to count comparisons
    {
        int &counter;
        CountComparisons(int &c) : counter(c) {}
        bool operator()(int a, int b)
        {
            counter++;
            logMessage("", C_GRAY "Compared " + asString(b) + " with " + asString(a) + C_CYAN"   Counter: " C_RESET + asString(counter));
            return a < b;
        };
    };

    PmergeMe(std::vector<int> input, int &iteration, int &comparisons);
    ~PmergeMe();
    // ADD COPY CONSTRUCTOR AND ASSIGN<EN OPERATOR!!!

    // getters
    std::vector<int> &getMain();

    std::vector<int> &getPend();

    std::vector<std::pair<int, int> > &getPairs();

    std::vector<size_t> &getJacobsthal();

    int &getRemainderInfo();

    int &getRemainderValue();

    int &getCounter();
    int &getRecursionLvl();

    void containerStatus();

    // change with sort pair
    void sortPair();
    void updatePend();
};
