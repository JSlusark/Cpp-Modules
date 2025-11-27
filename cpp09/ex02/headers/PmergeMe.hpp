#pragma once
#include "./debug.hpp"

class PmergeMe
{
private:
    std::vector<int> &mergedChains; // container to sort, passed as ref and changes
    std::vector<std::pair<int, int> > pairs; // container to preserve relationship between pairs sent to main and pend chains
    std::vector<int> main;                  // bigger values container
    std::vector<int> pend;                  // smaller values container
    std::vector<size_t> jacobsthal;
    int remainderValue;
    int has_remainder;
    int &counter; // counts amount of combinations done in each currentSet and scales between recursions

    void createChains();
    std::pair<int, int> orderPair(size_t i);


    /* ------------------------------JACOBSTAHL SEQUENCE FUNCTIONS--------------------------------- */
    void generateJacobsthal(); 
    void findNumbers(size_t pendSize);          // selects js numbers based on pend size (1, 3, 5.. etc)
    void completeSequence(size_t pendSize);    // fills in sequence (1, 3, 2, 5, 8, 7 ,6, 4.. etc)
    
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
    
    /* ------------------ CONSTRUCTORS ------------------ */
    PmergeMe(std::vector<int> &recursedSet, int &iteration, int &comparisons);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();
    
    /* ------------------------------ MERGE INSERTION --------------------------------- */
    void pleaseMergeMe();
    std::vector<int>::iterator getPartnerPosition(int value, int partner, int jacobNumber, int j);

    /* ------------------------------ GETTERS AND SETTERS --------------------------------- */
    std::vector<int> &getContainer();
    std::vector<int> &getMain();
    std::vector<int> &getPend();
    std::vector<std::pair<int, int> > &getPairs();
    std::vector<size_t> &getJacobsthal();
    int &getRemainderInfo();
    int &getRemainderValue();
    int &getCounter();
    int &getRecursionLvl();

    /* ------------------------------ SHOW SET INFO --------------------------------- */
    void printSetData();
    void printPairs() const;
    void printChain(const std::vector<int> &container, const std::string &name) const;
    void printJacobstahl(); 
    void printInsertionOrder();

    /* ------------------------------ PAIR INFO USED FOR INSERTION --------------------------------- */
    std::pair<int,int> getPairInfo(size_t jacob);

};
