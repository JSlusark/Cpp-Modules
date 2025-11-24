#pragma once
#include "./fordJohnsonSort.hpp"
#include "./debug.hpp"

class PmergeMe // or would be even called "iterationset"
{
private:
    std::vector<int> container; // container to sort

    std::vector<std::pair<int, int> > pairs; // container to preserve relationship between pairs sent to main and pend chains
    std::vector<int> main;                  // bigger values container
    std::vector<int> pend;                  // smaller values container

    size_t pendSize;
    std::vector<size_t> jacobsthal;

    int remainderValue;
    int has_remainder;

    int counter; // counts amount of combinations done in each set and scales between recursions

    void createChains();

/* ------------------------------JACOBSTAHL SEQUENCE FUNCTIONS--------------------------------- */
    void generateJacobsthal(); 
    void findNumbers();          // selects js numbers based on pend size (1, 3, 5.. etc)
    void completeSequence();    // fills in sequence (1, 3, 2, 5, 4.. etc)

public:
    int recursionLvl;

    struct CountComparisons // functor to count comparisons inside the lowerbound
    {
        int &counter;
        CountComparisons(int &c) : counter(c) {}
        bool operator()(int a, int b)
        {
            counter++;
            logMessage("", C_GRAY "Compared " + asString(b) + " with " + asString(a) + C_CYAN "   Counter: " C_RESET + asString(counter));
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
