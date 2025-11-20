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

    int comparisonCount;
    int remainderValue;
    int has_remainder;

    std::vector<size_t> findNumbers(size_t pend_size)
    {
        std::vector<size_t> seq;              // empty vector
        if (pend_size == 0 || pend_size == 1) // means that there are no pending elements, but where does this decrease?!
        {
            seq.push_back(pend_size); // adds 0 or 1 to seq depending on size
            return seq;
        }
        size_t j = 0;  // i assign this so i can start the loop?
        size_t j1 = 1; // n - 1 (prev)
        size_t j2 = 0; // n - 2 (prev_prev)
        for (size_t i = 0; j < pend_size; i++)
        {
            /* J(n) = J(n-1) + 2 * J(n-2)  */
            //         1    +    0
            j = (j1) + (2 * (j2));
            if (j < pend_size) // adds only if last generated j is < size
                seq.push_back(j);
            j2 = j1;
            j1 = j;
        }
        return seq;
    }

    std::vector<size_t> filledSequence(std::vector<size_t> &seq, size_t pend_size)
    {
        std::vector<size_t> filled;
        for (size_t i = 0; i < seq.size(); i++)
        {
            if (i == 0)
            {
                filled.push_back(seq[i]);
                continue;
            }
            size_t a = seq[i - 1]; // prev
            size_t b = seq[i];     // curr

            for (size_t n = b; n > a; n--)
                filled.push_back(n);
        }
        if (pend_size > seq.back())
        {
            size_t a = seq.back(); // prev
            size_t b = pend_size;  // curr
            for (size_t n = b; n > a; n--)
                filled.push_back(n);
        }
        // showContainer(filled, "Order", -1);
        return filled;
    }

    std::vector<size_t> generateJacobsthal() // n is size of pend_chain
    {
        std::vector<size_t> sequence = findNumbers(pend.size());
        return filledSequence(sequence, pend.size());
    }

    void createChains()
    {
        for (size_t i = 0; i < input.size(); i += 2) // we proceed by 2 input at a time
        {
            int a;
            int b;
            // creates the fake pair for the remainder
            if (input[i] == remainderValue && i == (input.size() - 1)) // checking input.size ensure we don't select duplicate values if present
            {
                a = remainderValue;
                b = -1;
            }
            else
            {
                // creates and sorts the real pairs before pusing to pairs
                a = input[i];     // first (smallest)
                b = input[i + 1]; // second (biggest) // wthis segfaults, and needs to be used only on non-paired
                if (a > b)        // swaps content for ascending order
                {
                    std::swap(a, b);
                    comparisonCount++; // increment comparison count from ford-johnson
                }
            }

            std::pair<int, int> keyPair(a, b);
            pairs.push_back(keyPair);
            if (b != -1)           // avoid dummy value gets pushed to main chain
                main.push_back(b); // only true values are pushed to chain
            pend.push_back(a);     // adds all small numbers + odd one to the pend
        }
    }

public:
    int recursionID;

    struct CountComparisons // functor to count comparisons
    {
        int &counter;
        CountComparisons(int &c) : counter(c) {}
        bool operator()(int a, int b)
        {
            counter++;
            return a < b;
        }
    };

    PmergeMe(std::vector<int> input, int &iteration, int &comparisons)
        : input(input),
          comparisonCount(comparisons),
          remainderValue(-1),
          has_remainder(0),
          recursionID(iteration)
    {
        has_remainder = (input.size() % 2 != 0); // if even it's false(0), if odd it's true(1)
        if (has_remainder)
            remainderValue = input.back();
        createChains();
        jacobsthal = generateJacobsthal();
        // std::cout << "Jacobsthal insertion order for pend[" << pend.size() << "]:" << std::endl;
    };
    ~PmergeMe() {};

    // getters
    std::vector<int> &getMain()
    {
        return main;
    }

    std::vector<int> &getPend()
    {
        return pend;
    }

    std::vector<std::pair<int, int> > &getPairs()
    {
        return pairs;
    }

    std::vector<size_t> &getJacobsthal()
    {
        return jacobsthal;
    }

    int &getRemainderInfo()
    {
        return has_remainder;
    }

    int &getRemainderValue()
    {
        return remainderValue;
    }

    int &getComparisonCount()
    {
        return comparisonCount;
    }


    void printStatus()
    {
        logMessage(C_CYAN "Recursion level: " C_RESET, asString(recursionID));
        showPairs(pairs, remainderValue);
        showContainer(main, "Main", remainderValue, has_remainder);
        showContainer(pend, "Pend", remainderValue, has_remainder);
    }

    // change with sort pair
    void sortPair()
    {
        if (main[0] > main[1])
        {
            std::swap(main[0], main[1]);
            comparisonCount++; // increment comparison count also here
        }
    }
};
